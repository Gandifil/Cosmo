//
// Created by Gandifil on 1/12/2019.
//

#ifndef COSMO_IUPDATEABLE_H
#define COSMO_IUPDATEABLE_H

#include <SFML/System/Time.hpp>

namespace Cosmo
{
    namespace Entity
    {
        class IUpdateable
        {
        public:
            virtual void Update(sf::Time dt) = 0;
        };
    }
}

#endif //COSMO_IUPDATEABLE_H
