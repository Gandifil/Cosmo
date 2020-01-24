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

		virtual void handleEvent(sf::Event event) override {
			gui.handleEvent(event);
		};

		virtual void update(sf::Time dt) override {
			gui.updateTime(dt);
		};

		virtual void Render() override {
			gui.draw();
		}

	protected:
		tgui::Gui gui;
	};
}
#endif