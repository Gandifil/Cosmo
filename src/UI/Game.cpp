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
	renderWindow.draw(pl1);
}

Game::Game(sf::RenderWindow& window):
	renderWindow{window},
	player{ new Cruiser{100, Cosmo::Info::Manager::Instance().Textures["starship1.png"], {500, 500} }},
	pl1{100, Cosmo::Info::Manager::Instance().Textures["starship1.png"], {500, 500} },
	kb{*player},
	controlling{ &kb }
{
	entities.players.Add(player);
}


Game::~Game()
{
}
