#include "Game.h"

using namespace Cosmo::UI;

void Game::handleEvent(sf::Event event)
{
	controlling.handleEvent(event);
}

void Game::update(sf::Time dt)
{
	gameDirector.Spawn(dt);
    Entities::Container::instance().checkCollision();
	Entities::Container::instance().update(dt);
    Entities::Container::instance().destroyDead();
	hpBar.UpdateValue();
}

void Game::Render()
{
    Entities::Container::instance().draw(renderWindow, sf::RenderStates{});
	renderWindow.draw(hpBar);
}

Game::Game(sf::RenderWindow& window, const Parameters& params):
	renderWindow{window},
	controlling{params.controlInit1},
	gameDirector{Entities::Container::instance()},
	hpBar{sf::Vector2f{1000, 1000}, 600.f, 50.f, *params.cruiser}
{
	auto size = window.getSize();
}
