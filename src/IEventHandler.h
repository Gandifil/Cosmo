//
// Created by Gandifil on 24.01.2020.
//

#ifndef COSMO_IEVENTHANDLER_H
#define COSMO_IEVENTHANDLER_H

#include <SFML/Window/Event.hpp>

namespace Cosmo {
    class IEventHandler {
    public:
        virtual bool handleEvent(sf::Event event) noexcept { return false; }
    };
}

#endif //COSMO_IEVENTHANDLER_H
