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

            Collision<Starship, Bullet> colliseBulToEnemies, colliseBulToPlayers;

            inline void Render(sf::RenderWindow &wnd) const
            {
                playersBullets.Draw(wnd, sf::RenderStates::Default);
                enemiesBullets.Draw(wnd, sf::RenderStates::Default);
                players.Draw(wnd, sf::RenderStates::Default);
                enemies.Draw(wnd, sf::RenderStates::Default);
            }

            inline void Update(sf::Time dt)
            {
                colliseBulToEnemies.Check();
                colliseBulToPlayers.Check();

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

            inline void Clear(){
                enemiesBullets.entities.clear();
                playersBullets.entities.clear();
                players.entities.clear();
                enemies.entities.clear();
            }

            static Service& Instance()
            {
                static Service instance;
                return instance;
            }
        private:
            Service():
                    colliseBulToEnemies{enemies, playersBullets},
                    colliseBulToPlayers{players, enemiesBullets}{}
        };
    }
}
#endif //COSMO_SERVICE_H
