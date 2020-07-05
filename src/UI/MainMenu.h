#pragma once
#include "Menu.h"

namespace Cosmo
{
	namespace UI {
		class MainMenu final: public Menu{
		public:
			MainMenu(sf::RenderWindow &wnd);

			virtual bool handleEvent(sf::Event event) noexcept override {
				return Menu::handleEvent(event);
			}

		private:
			tgui::Label::Ptr label;
			tgui::Button::Ptr button;
		};
	}
}
