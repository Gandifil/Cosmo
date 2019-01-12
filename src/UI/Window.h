#pragma once
#include <SFML/Graphics.hpp>
#include "../Info/Config.h"
#include "StarField.h"
#include "MainMenu.h"

namespace Cosmo
{
	namespace UI {
		class Window final {
		public:
			Window(const Info::Config &config);

			~Window();

			inline int MainLoop() {
				while (renderWindow.isOpen()) {
					if (ListenEvent())
						return EXIT_SUCCESS;

					Update(clock.restart());
					Render();
				}
				return EXIT_SUCCESS;
			}

		private:
			sf::RenderWindow renderWindow;

			const Info::Config &config;

			StarField stars;

			Scene *&scene;

			sf::Event event;
			sf::Clock clock;

			inline void Render();

			inline void Update(sf::Time dt);

			inline bool ListenEvent();
		};

		Window::Window(const Info::Config &config) :
				renderWindow{sf::VideoMode{(unsigned int) config.getParam(Info::Config::WWindow),
										   (unsigned int) config.getParam(Info::Config::HWindow)},
							 "Cosmo",
							 (sf::Uint32)
							 	(config.getParam(Info::Config::isFullScreen) ? sf::Style::Fullscreen : sf::Style::Default)},
				config{config},
				stars{renderWindow},
				scene{Scene::Instance()} {
			Scene::Add(new MainMenu(renderWindow));
		}

		Window::~Window() {
		}

		inline void Window::Render() {
			renderWindow.clear();
			renderWindow.draw(stars);
			scene->Render();
			renderWindow.display();
		}

		inline void Window::Update(sf::Time dt) {
			stars.Update(dt);
			scene->Update(dt);
		}

		inline bool Window::ListenEvent() {
			while (renderWindow.pollEvent(event))
				if ((scene->HandleEvent(event)) == 0)
					return true;
			return false;
		}
	}
}
