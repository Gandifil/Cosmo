//
// Created by Gandifil on 1/12/2019.
//
#pragma once

#include <TGUI/Vector2f.hpp>
#include <SFML/System.hpp>
#include "../Entity/Service.h"
#include "../Info/Manager.h"

namespace Cosmo
{
    namespace Utils
    {
        class Weapon
        {
        public:
            Weapon(const Info::WeaponBox& box, bool isPlayer):
                    shift{box.shift}, t{0}, reloadTime{box.reload},
                    createBulletBox{box.bulletBox},
                    handler{isPlayer ? Entity::Service::Instance().playersBullets:
                            Entity::Service::Instance().enemiesBullets}
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

                handler.Add(new Bullet{createBulletBox, shift + pos, dir});
            }

            float t, reloadTime;
            const Info::BulletBox& createBulletBox;
            sf::Vector2f shift;
            Handler<Bullet>& handler;
        };
    }
}
