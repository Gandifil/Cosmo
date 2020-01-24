//
// Created by Gandifil on 24.01.2020.
//

#ifndef COSMO_CONTROL_SYSTEM_H
#define COSMO_CONTROL_SYSTEM_H

#include "../IEventHandler.h"
#include "../IUpdatable.h"
#include "Controller.h"

namespace Cosmo::Control{
    class System: public IEventHandler, public IUpdatable  {
    public:
        System(std::initializer_list<Controller *> init_list) : controllers{init_list} { }

        inline void handleEvent(sf::Event event) override {
            for (auto item : controllers)
                item->onHandleEvent(event);
        }

        inline void update(sf::Time dt) override {
            for (auto item : controllers)
                item->ControlUpdate(dt);
        }

    private:
        std::vector<Controller *> controllers;
    };
}


#endif //COSMO_CONTROL_SYSTEM_H
