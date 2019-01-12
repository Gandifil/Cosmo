//
// Created by Gandifil on 1/12/2019.
//
#include "Handler.h"
#include "Starship.h"

#ifndef COSMO_SERVICE_H
#define COSMO_SERVICE_H

using namespace Cosmo::Entity;

namespace Cosmo {
    namespace Entity {
    class Service: public sf::Drawable{
        public:
            Handler<Starship> players;

            virtual void draw(sf::RenderTarget &wnd, sf::RenderStates states) const override
            {
                players.Draw(wnd, states);
            }
        private:

        };
    }
}
#endif //COSMO_SERVICE_H
