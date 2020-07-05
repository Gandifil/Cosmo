#include "Game.h"

using namespace Cosmo::UI;

void Game::handleEvent(sf::Event event)
{
	controlling.handleEvent(event);
}

void Game::update(sf::Time dt)
{
    hpBar.UpdateValue();
	gameDirector.Spawn(dt);

	static Entities::Container& container = Entities::Container::instance();
    container.checkCollision();
    container.update(dt);
	for(auto player: container.players)
	    if (player->isDead()) {
            Scene::backToLast();
            container.clear();
	        return;
	    }

    container.destroyDead();
}

void Game::draw(sf::RenderTarget &wnd, sf::RenderStates states) const noexcept {
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
