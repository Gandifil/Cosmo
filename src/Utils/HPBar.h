//
// Created by Gandifil on 1/22/2019.
//

#ifndef COSMO_HPBAR_H
#define COSMO_HPBAR_H

#include "ParameterBar.h"
#include "../Entities/Starship.h"

namespace Cosmo
{
    namespace Utils
    {
        class HPBar: public ParameterBar
        {
        public:
            HPBar(const sf::Vector2f& pos, float width, float height, const Cosmo::Entities::IHasHealthPoints& owner)
                    :ParameterBar{sf::Color::Green, pos, width, height}, hp{ owner}
            {}

            inline void UpdateValue()
            {
                setValue(hp.HP(), hp.maxHP());
            }

        private:
            const Cosmo::Entities::IHasHealthPoints& hp;
        };
    }
}
#endif //COSMO_HPBAR_H
