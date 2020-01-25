//
// Created by Gandifil on 24.01.2020.
//

#include "Keyboard.h"

using namespace Cosmo::Control;

Keyboard::Keyboard(IControllable &actor) : IController(actor) {
        shoot1 = sf::Keyboard::Space;
        shoot2 = sf::Keyboard::LControl;
        abil1 = sf::Keyboard::RShift;
        abil2 = sf::Keyboard::RControl;

        top = sf::Keyboard::W;
        down = sf::Keyboard::S;
        left = sf::Keyboard::A;
        right = sf::Keyboard::D;
}

void Keyboard::handleEvent(sf::Event event) {
    controlDirections();
    if (event.type == sf::Event::EventType::KeyReleased) {
        if (event.key.code == shoot1) actor.MainShoot();
        else if (event.key.code == shoot2) actor.AltShoot();
        else if (event.key.code == abil1) actor.MainAbility();
        else if (event.key.code == abil2) actor.AltAbility();
    }
}

inline void Keyboard::controlDirections() {
    Directions buffer;
    buffer.top = sf::Keyboard::isKeyPressed(top);
    buffer.down = sf::Keyboard::isKeyPressed(down);
    buffer.left = sf::Keyboard::isKeyPressed(left);
    buffer.right = sf::Keyboard::isKeyPressed(right);
    actor.directions = buffer;
}