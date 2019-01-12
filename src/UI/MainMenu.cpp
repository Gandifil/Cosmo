#include "MainMenu.h"
#include "../Info/Config.h"
#include "Game.h"

using namespace Cosmo::UI;
using namespace tgui;

MainMenu::MainMenu(sf::RenderWindow &wnd) : 
	Menu{ wnd },
	label{Label::create("Hello, my padavan!")},
	button{Button::create("Play")}
{
	gui.add(label);
	gui.add(button);

	Cosmo::Info::Config &conf = Cosmo::Info::Config::Instance();
	int width = conf.getParam(Cosmo::Info::Config::ConfigParam::WWindow);
	int height = conf.getParam(Cosmo::Info::Config::ConfigParam::HWindow);

	label->setPosition(width / 2, height / 3);
	label->setTextSize(80);

	button->setPosition("50%", "60%");
	button->setSize("10%", "10%");
	button->connect("pressed", [&]() 
	{
		Add(new Game{wnd});
	});
}
