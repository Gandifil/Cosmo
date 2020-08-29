//
// Created by Gandifil on 1/13/2019.
//
#pragma once

#include "../Starship.h"
#include "../../Info/Config.h"
#include "ctime"

namespace Cosmo
{
    namespace Entity
    {
        class Scout final : public Entities::Starship
        {
        public:
            struct Parameters : public Entities::Starship::Parameters {
                Parameters(const sol::table& lua):
                        Entities::Starship::Parameters{ lua },
                        cannon{Info::ResourcesStorage::get<sf::Texture>(lua["texture"])},
                        weapon{ lua["weapon"].get<sol::table>() }{}

                Utils::Weapon::Parameters weapon;
                const sf::Texture& cannon;
            };

            Scout(const Parameters& parameters, const sf::Vector2f& pos):
                Starship{parameters, pos}, weapon{parameters.weapon, false}
            {
                Info::Config& conf = Info::Config::Instance();
                int w = conf.getParam(Info::Config::WWindow);
                int h = conf.getParam(Info::Config::HWindow);

                dstPoint = {float(std::rand() % w), float(std::rand() % h)};
                sprite.setRotation(180.f);
            }

            void update(sf::Time dt) override
            {
                auto pos = sprite.getPosition();
                sf::Vector2f delta = dstPoint - pos;
                float sc = dt.asSeconds();
                float top = parameters.up * sc;
                float down = parameters.down * sc;
                float side = parameters.side * sc;
                if (abs(delta.x) > side)
                    delta.x = (delta.x > 0)? side : -side;

                if (delta.y > 0)
                {
                    if (abs(delta.y) > top)
                        delta.y = top;
                }
                else
                if (abs(delta.y) > down)
                    delta.y = -down;

                sprite.move(delta);

                weapon.FireAlways(pos,
                        Entities::Container::instance().players.front()->position() - pos, dt);
            }

            virtual int team() const noexcept {
                return 1;
            };

        private:
            sf::Vector2f dstPoint;
            Utils::Weapon weapon;
        };
    }
}
