#include "Game.h"
#include "../Info/Manager.h"
#include "../Entity/Enemy/Scout.h"

using namespace Cosmo::UI;

int Game::HandleEvent(sf::Event event)
{
	controlling.onHandleEvent(event);
	return 1;
}

void Game::Update(sf::Time dt)
{
	controlling.Update(dt);
	gameDirector.Spawn(dt);

	entities.Update(dt);
	hpBar.UpdateValue();
}

void Game::Render()
{
	entities.Render(renderWindow);
	renderWindow.draw(hpBar);
}

Game::Game(sf::RenderWindow& window, const Parameters& params):
	renderWindow{window},
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
