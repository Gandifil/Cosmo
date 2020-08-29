//
// Created by Gandifil on 24.01.2020.
//

#include "Keyboard.h"

using namespace Cosmo::Control;

Keyboard::Keyboard(IControllable &actor) noexcept : IController(actor) {
        shoot1 = sf::Keyboard::Space;
        shoot2 = sf::Keyboard::LControl;
        abil1 = sf::Keyboard::RShift;
        abil2 = sf::Keyboard::RControl;

        top = sf::Keyboard::W;
        down = sf::Keyboard::S;
        left = sf::Keyboard::A;
        right = sf::Keyboard::D;
}

bool Keyboard::handleEvent(sf::Event event) noexcept {
    controlDirections();
    if (event.type == sf::Event::EventType::KeyPressed) {
        if (event.key.code == shoot1) {
            actor.mainShoot();
            return true;
        }
        if (event.key.code == shoot2) {
            actor.altShoot();
            return true;
        }
        if (event.key.code == abil1) {
            actor.mainAbility();
            return true;
        }
        if (event.key.code == abil2) {
            actor.altAbility();
            return true;
        }
    }
    return false;
}

inline void Keyboard::controlDirections() {
    auto& buffer = actor.directions;
    buffer.top = sf::Keyboard::isKeyPressed(top);
    buffer.down = sf::Keyboard::isKeyPressed(down);
    buffer.left = sf::Keyboard::isKeyPressed(left);
    buffer.right = sf::Keyboard::isKeyPressed(right);
}