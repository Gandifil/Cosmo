//
// Created by Gandifil on 1/25/2019.
//

#include "GameOver.h"
#include "MainMenu.h"

using namespace Cosmo::UI;
using namespace tgui;


int GameOver::HandleEvent(sf::Event event)
{
    Menu::HandleEvent(event);
    if (event.type == sf::Event::KeyPressed)
        if (event.key.code == sf::Keyboard::Space ||
            event.key.code == sf::Keyboard::Escape)
            Scene::Turn(new MainMenu{renderWindow});
    return 1;
}

GameOver::GameOver(sf::RenderWindow &wnd, const Statistics& stats):
    Menu{ wnd },
    label{Label::create("GAME OVER! " + std::to_string(stats.points) + " POINTS!")},
    underLabel{Label::create("Press SPACE or ESCAPE to return on start")}
{
    gui.add(underLabel);
    gui.add(label);

    label->setPosition("0%", "40%");
    label->setSize("100%", "20%");
    label->setHorizontalAlignment(Label::HorizontalAlignment::Center);
    label->setTextSize(50);
    label->getRenderer()->setTextColor(sf::Color::White);

    underLabel->setPosition("0%", "60%");
    underLabel->setSize("100%", "10%");
    underLabel->setHorizontalAlignment(Label::HorizontalAlignment::Center);
    underLabel->setTextSize(20);
    underLabel->getRenderer()->setTextColor(sf::Color::White);
}