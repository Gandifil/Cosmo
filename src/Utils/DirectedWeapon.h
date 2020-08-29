//
// Created by Gandifil on 1/12/2019.
//

#pragma once

#include "Weapon.h"

namespace Cosmo
{
    namespace Utils
    {
        class DirectedWeapon final: public Weapon
        {
        public:
            DirectedWeapon(const Weapon::Parameters& parameters, bool isPlayer):
                    Weapon{parameters, isPlayer}, direction{parameters.direction}
            {}

            inline bool TryFire(const sf::Vector2f& pos)
            {
                return Weapon::TryFire(pos, direction);
            }

            inline bool FireAlways(const sf::Vector2f& pos, sf::Time dt)
            {
                Update(dt);
                return TryFire(pos);
            }

        private:
            sf::Vector2f direction;
        };
    }
}
