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
}

void Game::Render()
{
	entities.Render(renderWindow);
}

Game::Game(sf::RenderWindow& window, const Parameters& params):
	renderWindow{window},
	controlling{params.controlInit1, params.controlInit2},
	entities{Entity::Service::Instance()}
{
	entities.players.Add(params.cruiser);
}

Game::~Game()
{
}
