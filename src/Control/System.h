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
        System(std::initializer_list<IController*> init_list) : controllers{init_list} { }

        inline void handleEvent(sf::Event event) override {
            for (auto item : controllers)
                item->handleEvent(event);
        }

    private:
        std::vector<IController*> controllers;
    };
}

#endif //COSMO_CONTROL_SYSTEM_H
