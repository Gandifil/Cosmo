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
        class Weapon final
        {
        public:
            Weapon(const Info::WeaponBox& box):
                    aim{box.direction}, shift{box.shift}, t{0}, reloadTime{box.reload}
            {}

            inline void Update(sf::Time dt)
            {
                if (t > 0) t-= dt.asSeconds();
            }

            inline bool isReady()
            {
                return t <= 0.0001;
            }

            inline bool TryFire(const sf::Vector2f& pos)
            {
                if (isReady())
                {
                    Fire(pos);
                    return true;
                }
                return false;
            }

            inline bool FireAlways(const sf::Vector2f& pos, sf::Time dt)
            {
                Update(dt);
                return TryFire(pos);
            }

        private:

            inline void Fire(const sf::Vector2f& pos)
            {
                t = reloadTime;

                auto gunPos = pos + shift;
                Entity::Service::Instance().playersBullets.Add(
                        new Bullet{Info::Manager::Instance().Textures["laserCruiser01.png"],
                                   gunPos, gunPos + aim});
            }

            float t, reloadTime;
            sf::Vector2f shift, aim;
        };
    }
}
