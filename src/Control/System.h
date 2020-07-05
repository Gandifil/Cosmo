//
// Created by Gandifil on 24.01.2020.
//

#ifndef COSMO_CONTROL_SYSTEM_H
#define COSMO_CONTROL_SYSTEM_H

#include "../IEventHandler.h"
#include "../IUpdatable.h"
#include "IController.h"

namespace Cosmo::Control {
    class System: public IEventHandler {
    public:
        explicit System(std::initializer_list<IController*> init_list) noexcept : controllers{init_list} { }

        inline bool handleEvent(sf::Event event) noexcept override {
            for (auto item : controllers)
                if (item->handleEvent(event))
                    return true;
        }

    private:
        std::vector<IController*> controllers;
    };
}

#endif //COSMO_CONTROL_SYSTEM_H
