//
// Created by Gandifil on 24.01.2020.
//

#ifndef COSMO_IEVENTHANDLER_H
#define COSMO_IEVENTHANDLER_H

namespace Cosmo {
    class IEventHandler {
    public:
        virtual void handleEvent(sf::Event event) = 0;
    };
}

#endif //COSMO_IEVENTHANDLER_H
