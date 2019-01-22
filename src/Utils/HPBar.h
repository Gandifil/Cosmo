//
// Created by Gandifil on 1/22/2019.
//

#ifndef COSMO_HPBAR_H
#define COSMO_HPBAR_H

#include "ParameterBar.h"
#include "../Entity/Starship.h"

namespace Cosmo
{
    namespace Utils
    {
        class HPBar: public ParameterBar
        {
        public:
            HPBar(const sf::Vector2f& pos, float width, float height, const Cosmo::Entity::IHPOwner& owner)
                    :ParameterBar{sf::Color::Green, pos, width, height}, owner{ owner}
            {}

            inline void UpdateValue()
            {
                setValue(owner.getHP(), owner.getMaxHP());
            }

        private:
            const Cosmo::Entity::IHPOwner& owner;
        };
    }
}
#endif //COSMO_HPBAR_H
