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
        class Scout final : public Starship
        {
        public:
            Scout(const sf::Vector2f& pos, const Info::StarshipBox& box):
                Starship{pos, box}
            {
                Info::Config& conf = Info::Config::Instance();
                int w = conf.getParam(Info::Config::WWindow);
                int h = conf.getParam(Info::Config::HWindow);

                dstPoint = {float(std::rand() % w), float(std::rand() % h)};
                sprite.setRotation(180.f);
            }

            void Update(sf::Time dt) override
            {
                sf::Vector2f delta = dstPoint - sprite.getPosition();
                float sc = dt.asSeconds();
                float top = speed.top * sc;
                float down = speed.down * sc;
                float side = speed.side * sc;
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
            }

        private:
            sf::Vector2f dstPoint;
        };
    }
}