#pragma once
#include <SFML/Graphics.hpp>
#include "../Info/Config.h"
#include "StarField.h"
#include "FPSService.h"
#include "Scene.h"

namespace Cosmo::UI
{
	class Window final {
	public:
		Window(const Info::Config &config);

		inline void Render();

		inline void Update(sf::Time dt);

		inline sf::RenderWindow& getRenderWindow() {
			return renderWindow;
		}
	private:
		sf::RenderWindow renderWindow;
		StarField stars;
		FPSService fps;
	};

	Window::Window(const Info::Config &config) :
			renderWindow{sf::VideoMode{(unsigned int) config.getParam(Info::Config::WWindow),
									   (unsigned int) config.getParam(Info::Config::HWindow)},
						 "Cosmo",
						 (sf::Uint32)
							(config.getParam(Info::Config::isFullScreen) ? sf::Style::Fullscreen : sf::Style::Default)},
			stars{renderWindow} {
	}

	inline void Window::Render() {
		renderWindow.clear();
		renderWindow.draw(stars);
		Scene::Instance()->Render();
		renderWindow.draw(fps);
		renderWindow.display();
	}

	inline void Window::Update(sf::Time dt) {
		stars.Update(dt);
		fps.Update(dt);
	}
}
