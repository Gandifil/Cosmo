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
	//for (auto&& obj : starship)
	//	obj.Update(dt);
}

void Game::Render()
{
	window.draw(player);
}

Game::Game(sf::RenderWindow& window):
	window{window},
	player{ 100, Cosmo::Info::Manager::Instance().Textures["starship1.png"], {500, 500} },
	kb{player},
	controlling{ &kb }
{
	//starship.push_front();
}


Game::~Game()
{
}
