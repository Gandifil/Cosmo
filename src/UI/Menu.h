#pragma once
#include "Scene.h"
#include <TGUI/TGUI.hpp>

namespace Cosmo
{
	namespace UI {
		class Menu : public Scene {
		public:
			Menu(sf::RenderWindow &wnd) : gui{wnd} {};

			virtual int HandleEvent(sf::Event event) override {
				gui.handleEvent(event);
				return 1;
			};

			virtual void Update(sf::Time dt) override {};

			virtual void Render() override {
				gui.draw();
			}

		protected:
			tgui::Gui gui;
		};
	}
}