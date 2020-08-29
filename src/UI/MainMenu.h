#pragma once
#include "Menu.h"
#include "Animation.h"

namespace Cosmo
{
	namespace UI {
		class MainMenu final: public Menu{
		public:
			MainMenu(sf::RenderWindow &wnd);

			virtual bool handleEvent(sf::Event event) noexcept override {
				return Menu::handleEvent(event);
			}

            virtual void update(sf::Time dt) override {
                Menu::update(dt);
                animation.update(dt);
            };

            inline void draw(sf::RenderTarget &target, sf::RenderStates states) const noexcept override {
                Menu::draw(target, states);
                target.draw(animation, states);
            }

		private:
		    Animation animation;
			tgui::Label::Ptr label;
			tgui::Button::Ptr button;
		};
	}
}
