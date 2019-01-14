//
// Created by Gandifil on 1/12/2019.
//
#include "Handler.h"
#include "Starship.h"
#include "Bullet.h"
#include "Collision.h"

#ifndef COSMO_SERVICE_H
#define COSMO_SERVICE_H

using namespace Cosmo::Entity;

namespace Cosmo {
    namespace Entity {
    class Service{
        public:
            Handler<Starship> players,  enemies;
            Handler<Bullet> playersBullets, enemiesBullets;

            Collision<Starship, Bullet> colliseBulToEnemy;

            inline void Render(sf::RenderWindow &wnd) const
            {
                playersBullets.Draw(wnd, sf::RenderStates::Default);
                enemiesBullets.Draw(wnd, sf::RenderStates::Default);
                players.Draw(wnd, sf::RenderStates::Default);
                enemies.Draw(wnd, sf::RenderStates::Default);
            }

            inline void Update(sf::Time dt)
            {
                colliseBulToEnemy.Check();

                enemiesBullets.Update(dt);
                playersBullets.Update(dt);
                players.Update(dt);
                enemies.Update(dt);

                // Remove Deads calls
                players.RemoveDeads();
                enemies.RemoveDeads();
                enemiesBullets.RemoveDeads();
                playersBullets.RemoveDeads();
            }

            static Service& Instance()
            {
                static Service instance;
                return instance;
            }
        private:
            Service():
                colliseBulToEnemy{enemies, playersBullets} {}
        };
    }
}
#endif //COSMO_SERVICE_H
