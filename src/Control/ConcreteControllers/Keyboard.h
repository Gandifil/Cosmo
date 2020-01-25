//
// Created by Gandifil on 24.01.2020.
//

#ifndef COSMO_KEYBOARD_H
#define COSMO_KEYBOARD_H

#include "../IController.h"

namespace Cosmo::Control {
    class Keyboard : public IController {
    public:
        Keyboard(IControllable &actor);

        virtual void handleEvent(sf::Event event) override;

    private:
        sf::Keyboard::Key shoot1, shoot2, abil1, abil2;
        sf::Keyboard::Key top, down, left, right;

        inline void controlDirections();
    };
}

#endif //COSMO_KEYBOARD_H
