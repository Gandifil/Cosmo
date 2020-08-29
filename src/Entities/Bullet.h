//
// Created by Gandifil on 1/12/2019.
//
#pragma once

#include <TGUI/Vector2f.hpp>
#include "IDestroyable.h"
#include "EntitySprite.h"
#include "../Utils/Trajectory.h"
#include "../Info/Config.h"
#include <sol/sol.hpp>
#include "../Utils/VectorUtils.h"
#include "../Info/ResourcesStorage.h"
#include "IEntity.h"

namespace Cosmo {
    namespace Entities {
        class Bullet : public Entities::IEntity {
        public:
            struct Parameters {
                explicit Parameters(const sol::table& lua):
                    texture{Info::ResourcesStorage::get<sf::Texture>(lua["texture"])} {
                    //trajectoryNum = lua["trajectoryNum"];
                    speed = lua.get_or("speed", 0.);
                }

                const sf::Texture& texture;
                //int trajectoryNum;
                float speed;
            };

            Bullet(const Parameters &parameters, int team, const sf::Vector2f &pos, const sf::Vector2f &dir) :
                    sprite{parameters.texture, pos}, _team{ team },
                    trajectory(pos, Utils::Normalize(dir), Cosmo::Utils::linear10, parameters.speed)
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

            virtual void colliseWith(const IEntity* entity) noexcept override {
                Die();
            }

            Entities::EntitySprite sprite;

            virtual int team() const noexcept {
                return _team;
            };

            inline virtual const sf::Vector2f& position() const noexcept override{
                return sprite.getPosition();
            }

        protected:
            virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
                sprite.drawUsingShader(target, states);
            }

        private:
            Cosmo::Utils::Trajectory trajectory;
            int _team;
        };
    }
}
