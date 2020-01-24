#pragma once
#include "Menu.h"

namespace Cosmo
{
	namespace UI {
		class MainMenu final: public Menu{
		public:
			MainMenu(sf::RenderWindow &wnd);

			virtual void handleEvent(sf::Event event) override {
				Menu::handleEvent(event);
				//return (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) ? 0 : 1;
			}

		private:
			tgui::Label::Ptr label;
			tgui::Button::Ptr button;
		};
	}
}
