//
// Created by Gandifil on 24.01.2020.
//

#ifndef COSMO_UI_MENU
#define COSMO_UI_MENU

#include "Scene.h"
#include <TGUI/TGUI.hpp>

namespace Cosmo::UI {
	class Menu : public Scene {
	public:
		Menu(sf::RenderWindow &wnd) : gui{wnd} {};

		virtual bool handleEvent(sf::Event event) noexcept override {
			return gui.handleEvent(event);
		};

		virtual void update(sf::Time dt) override {
			gui.updateTime(dt);
		};

        inline void draw(sf::RenderTarget &wnd, sf::RenderStates states) const noexcept {
            gui.draw();
        }

	protected:
		mutable tgui::Gui gui;
	};
}
#endif