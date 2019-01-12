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
    class Service{
        public:
            Handler<Starship> players;

            inline void Render(sf::RenderWindow &wnd) const
            {
                players.Draw(wnd, sf::RenderStates::Default);
            }

            inline void Update(sf::Time dt)
            {
                // Remove Deads calls
                //players.RemoveDeads();
            }
        private:

        };
    }
}
#endif //COSMO_SERVICE_H
