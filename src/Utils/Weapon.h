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
            Weapon(const sf::Vector2f& shift, const sf::Vector2f& aim, float reloadTime):
                    aim{aim}, shift{shift}, t{0}, reloadTime{reloadTime}
            {}

            inline void Update(sf::Time dt)
            {
                if (t > 0) t-= dt.asSeconds();
            }

            inline bool isReady()
            {
                return t <= 0.0001;
            }

            inline void Fire(const sf::Vector2f& pos)
            {
                if (isReady())
                {
                    t = reloadTime;

                    auto gunPos = pos + shift;
                    Entity::Service::instance->bullets.Add(
                            new Bullet{Info::Manager::Instance().Textures["laserRed01.png"],
                                       gunPos, gunPos + aim});
                }
            }

        private:
            float t, reloadTime;
            sf::Vector2f shift, aim;
        };
    }
}
