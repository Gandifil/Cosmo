//
// Created by Gandifil on 24.01.2020.
//

#ifndef COSMO_KEYBOARD_H
#define COSMO_KEYBOARD_H

#include "../IController.h"

namespace Cosmo::Control {
    class Keyboard : public IController {
    public:
        explicit Keyboard(IControllable &actor) noexcept;

        virtual bool handleEvent(sf::Event event) noexcept override;

    private:
        sf::Keyboard::Key shoot1, shoot2, abil1, abil2;
        sf::Keyboard::Key top, down, left, right;

        inline void controlDirections() ;
    };
}

#endif //COSMO_KEYBOARD_H
