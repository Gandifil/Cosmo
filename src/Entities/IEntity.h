//
// Created by Gandifil on 27.01.2020.
//

#ifndef COSMO_IENTITY_H
#define COSMO_IENTITY_H

#include <SFML/Graphics/Drawable.hpp>
#include "../IUpdatable.h"
#include "IDestroyable.h"

namespace Cosmo::Entities {
    class IEntity:  public sf::Drawable, public IUpdatable, public Cosmo::Entity::IDestroyable {

    };
}
#endif //COSMO_IENTITY_H
