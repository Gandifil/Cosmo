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
	sf::Vector2f pos{500, 500};
	entities.bullets.Add(new Bullet{Info::Manager::Instance().Textures["laserGreen02.png"],
					  pos, pos + sf::Vector2f{0.f, -100.f}});
	//Entity::Service::instance = & entities;
}


Game::~Game()
{
}
