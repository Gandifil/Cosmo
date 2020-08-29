#include "Game.h"
#include "MainMenu.h"

using namespace Cosmo::UI;
using namespace tgui;

MainMenu::MainMenu(sf::RenderWindow &wnd) : 
	Menu{ wnd },
	label{Label::create("COSMO!")},
	button{Button::create("Play")},
    animation{ Info::ResourcesStorage::get<sf::Texture>("title.png"), 9}
{
	gui.add(label);
	gui.add(button);

	Cosmo::Info::Config &conf = Cosmo::Info::Config::Instance();
	int width = conf.getParam(Cosmo::Info::Config::ConfigParam::WWindow);
	int height = conf.getParam(Cosmo::Info::Config::ConfigParam::HWindow);
    animation.setPosition(width / 2., height / 2.);

	label->setPosition("50%", "40%");
	label->setAutoSize(true);
	label->setTextSize(80);
	label->getRenderer()->setTextColor(sf::Color::Cyan);

	button->setPosition("50%", "60%");
	button->setSize("10%", "10%");
	button->setTextSize(35);
	button->connect("pressed", [&]() {
		Scene::toNext(std::make_unique<Game>(wnd));
	});
}
