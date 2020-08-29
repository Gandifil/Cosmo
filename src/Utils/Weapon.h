//
// Created by Gandifil on 1/12/2019.
//
#pragma once

#include <TGUI/Vector2f.hpp>
#include <SFML/System.hpp>
#include <sol/sol.hpp>
#include "../Entities/Container.h"
#include "../Entities/Bullet.h"

namespace Cosmo
{
    namespace Utils
    {
        class Weapon
        {
        public:
            struct Parameters {
                Parameters(const sol::table& lua):
                    bullet{ Info::ResourcesStorage::get<Entities::Bullet::Parameters>(lua["bullet"]) } {
                    reload = lua.get_or("reload", 1.);
                    shift.x = lua["shift"]["x"];
                    shift.y = lua["shift"]["y"];
                    direction.x = lua["direction"]["x"];
                    direction.y = lua["direction"]["y"];
                }

                const Entities::Bullet::Parameters& bullet;
                float reload;
                sf::Vector2f shift, direction;
            };

            Weapon(const Parameters& parameters, bool isPlayer):
                    shift{parameters.shift}, t{0}, reloadTime{parameters.reload},
                    bullet{parameters.bullet}, team{ isPlayer? 0 : 1 }
            {}

            inline void Update(sf::Time dt)
            {
                if (t > 0) t-= dt.asSeconds();
            }

            inline bool isReady()
            {
                return t <= 0;
            }

            inline bool TryFire(const sf::Vector2f& pos, const sf::Vector2f& dir)
            {
                if (isReady())
                {
                    Fire(pos, dir);
                    return true;
                }
                return false;
            }

            inline bool FireAlways(const sf::Vector2f& pos, const sf::Vector2f& dir, sf::Time dt)
            {
                Update(dt);
                return TryFire(pos, dir);
            }

        private:

            inline void Fire(const sf::Vector2f& pos, const sf::Vector2f& dir)
            {
                t = reloadTime;

                Entities::Container::instance().add<Entities::Bullet>(
                        bullet, team, shift + pos, dir);
            }

            float t, reloadTime;
            const Entities::Bullet::Parameters& bullet;
            sf::Vector2f shift;
            int team;
        };
    }
}
