//
// Created by Gandifil on 27.01.2020.
//

#ifndef COSMO_IENTITY_H
#define COSMO_IENTITY_H

#include <SFML\\Graphics.hpp>
#include "../IUpdatable.h"
#include "IDestroyable.h"
#include "ICollisionable.h"

namespace Cosmo::Entities {
    class IEntity: public sf::Drawable, public IUpdatable, public IDestroyable, public ICollisionable {
    public:
        inline virtual const sf::Vector2f& position() const noexcept = 0;
        virtual int team() const noexcept  = 0;
    };
}

#endif //COSMO_IENTITY_H
