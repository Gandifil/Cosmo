//
// Created by Gandifil on 1/12/2019.
//
#pragma once

#include <TGUI/Vector2f.hpp>
#include "IDestroyable.h"
#include "ISpriteOwner.h"
#include "IUpdateable.h"
#include "../Utils/Trajectory.h"
#include "../Info/Config.h"

namespace Cosmo
{
    namespace Entity {
        class Bullet : public IDestroyable, public ISpriteOwner, public IUpdateable {
        public:
            Bullet(const sf::Texture &texture, const sf::Vector2f &vec, const sf::Vector2f &dst) :
                    ISpriteOwner{texture, vec},
                    trajectory{vec, dst, Cosmo::Utils::linear10}
                    {}

            virtual void Update(sf::Time dt) override
            {
                static Info::Config& conf = Info::Config::Instance();
                static float w = (float)(conf.getParam(Info::Config::WWindow));
                static float h = (float)(conf.getParam(Info::Config::HWindow));

                auto newPos = trajectory.UpdatePosition(dt);
                sf::FloatRect rect{-w, -h, 2 * w, 2 * h};
                if (rect.contains(newPos))
                    sprite.setPosition(newPos);
                else Die();
            }

            inline void ColliseEvent(Starship& entity)
            {
                entity.Damage(100);
                Die();
            }

        private:
            Cosmo::Utils::Trajectory trajectory;
        };
    }
}
