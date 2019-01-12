//
// Created by Gandifil on 1/12/2019.
//
#include "Handler.h"
#include "Starship.h"
#include "Bullet.h"

#ifndef COSMO_SERVICE_H
#define COSMO_SERVICE_H

using namespace Cosmo::Entity;

namespace Cosmo {
    namespace Entity {
    class Service{
        public:
            Handler<Starship> players;
            Handler<Bullet> bullets;

            inline void Render(sf::RenderWindow &wnd) const
            {
                bullets.Draw(wnd, sf::RenderStates::Default);
                players.Draw(wnd, sf::RenderStates::Default);
            }

            inline void Update(sf::Time dt)
            {
                bullets.Update(dt);
                players.Update(dt);

                // Remove Deads calls
                players.RemoveDeads();
                bullets.RemoveDeads();
            }

            static Service *instance;
        private:

        };
    }
}
#endif //COSMO_SERVICE_H
