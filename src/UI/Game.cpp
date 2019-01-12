#include "Game.h"
#include "../Info/Manager.h"

using namespace Cosmo::UI;

int Game::HandleEvent(sf::Event event)
{
	controlling.onHandleEvent(event);
	return 1;
}

void Game::Update(sf::Time dt)
{
	controlling.Update(dt);

	entities.Update(dt);
}

void Game::Render()
{
	entities.Render(renderWindow);
}

Game::Game(sf::RenderWindow& window, const Parameters& params):
	renderWindow{window},
	controlling{params.controlInit}
{
	entities.players.Add(params.cruiser);
}


Game::~Game()
{
}
