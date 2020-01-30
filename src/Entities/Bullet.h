//
// Created by Gandifil on 1/12/2019.
//
#pragma once

#include <TGUI/Vector2f.hpp>
#include "IDestroyable.h"
#include "EntitySprite.h"
#include "../Utils/Trajectory.h"
#include "../Info/Config.h"
#include "../Utils/VectorUtils.h"
#include "IEntity.h"
#include "../Info/TypeBoxes.h"

namespace Cosmo
{
    namespace Entity {
        class Bullet : public Entities::IEntity {
        public:
            Bullet(const Info::BulletBox &box, const sf::Vector2f &pos, const sf::Vector2f &dir) :
                    sprite{box.texture, pos},
                    trajectory(pos, Utils::Normalize(dir), Cosmo::Utils::linear10, box.speed)
                    {}

            virtual void update(sf::Time dt) override
            {
                static Info::Config& conf = Info::Config::Instance();
                static float w = (float)(conf.getParam(Info::Config::WWindow));
                static float h = (float)(conf.getParam(Info::Config::HWindow));

                auto newPos = trajectory.UpdatePosition(dt);
                sf::FloatRect rect{-w, -h, 2 * w, 2 * h};
                if (rect.contains(newPos))
                    sprite.setPosition(newPos);
                else Die();

                sprite.setRotation(trajectory.GetAngle());
            }
//
//            inline void ColliseEvent(Starship& entity)
//            {
//                entity.Damage(100);
//                Die();
//            }
        protected:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
                sprite.drawUsingShader(target, states);
            }
        private:
            Entities::EntitySprite sprite;
            Cosmo::Utils::Trajectory trajectory;
        };
    }
}
