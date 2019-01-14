//
// Created by Gandifil on 1/14/2019.
//
#pragma once
#include "Service.h"
#include "Enemy/Scout.h"
#include "../Info/Manager.h"

namespace Cosmo
{
    namespace Entity
    {
        class GameDirector final
        {
        public:
            GameDirector(): entities{Service::Instance()}{};

            inline void Spawn(sf::Time dt)
            {
                static float spawnTime = 10;

                const float spawnEnemy = 10;

                if (spawnTime >= spawnEnemy)
                {
                    entities.enemies.Add(new Scout{
                            sf::Vector2f{500.f, 0.f},
                            Info::Manager::Instance().Cruisers["scout1"].starshipBox});

                    spawnTime = 0;
                }

                spawnTime += dt.asSeconds();
            }

        private:
            Service& entities;
        };
    }
}
