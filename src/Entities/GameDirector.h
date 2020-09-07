//
// Created by Gandifil on 1/14/2019.
//
#pragma once
#include "Container.h"
#include "Enemies/Scout.h"

namespace Cosmo
{
    namespace Entity
    {
        class GameDirector final
        {
        public:

            GameDirector(Entities::Container& container): entities{ container } {};

            inline void Spawn(sf::Time dt)
            {
                static float spawnTime = 10;

                const float spawnEnemy = 10;

                if (spawnTime >= spawnEnemy) {
                    entities.add<Cosmo::Entities::Enemies::Scout>(
                            "entities/core.lua",
                            sf::Vector2f{500.f, 0.f});

                    spawnTime = 0;
                }

                spawnTime += dt.asSeconds();
            }

        private:
            Entities::Container& entities;
        };
    }
}
