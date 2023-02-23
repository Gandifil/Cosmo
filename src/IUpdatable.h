//
// Created by Gandifil on 24.01.2020.
//

#ifndef COSMO_IUPDATABLE_H
#define COSMO_IUPDATABLE_H

#include <SFML/System/Time.hpp>

namespace Cosmo {
    class IUpdatable {
    public:
        virtual ~IUpdatable() = default;
        virtual void update(sf::Time dt) = 0;
    };
}
#endif //COSMO_IUPDATABLE_H
