#include "Game.h"
#include "../Info/Manager.h"
#include "../Entity/Enemy/Scout.h"
#include "GameOver.h"

using namespace Cosmo::UI;

int Game::HandleEvent(sf::Event event)
{
	controlling.onHandleEvent(event);
	return 1;
}

void Game::Update(sf::Time dt)
{
	hpBar.UpdateValue();
	controlling.Update(dt);
	gameDirector.Spawn(dt);

	entities.Update(dt);
	if (entities.players.entities.empty())
	    Exit();
}

void Game::Exit()
{
    entities.Clear();
    Scene::Turn(new GameOver{renderWindow, GameOver::Statistics{100}});
}

void Game::Render()
{
	entities.Render(renderWindow);
	renderWindow.draw(hpBar);
}

Game::Game(sf::RenderWindow& window, const Parameters& params):
    Scene{window},
	controlling{params.controlInit1, params.controlInit2},
	entities{Entity::Service::Instance()},
	hpBar{sf::Vector2f{1000, 1000}, 600.f, 50.f, *params.cruiser}
{
	auto size = window.getSize();
	entities.players.Add(params.cruiser);
}

Game::~Game()
{
}
