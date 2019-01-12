//
// Created by Gandifil on 1/12/2019.
//

#pragma once


#include <TGUI/Vector2f.hpp>
#include "IDestroyable.h"
#include "ISpriteOwner.h"
#include "IUpdateable.h"
#include "../Utils/Trajectory.h"

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
                auto newPos = trajectory.UpdatePosition(dt);

                sf::View view;
                auto size = view.getSize();
                sf::FloatRect rect{-size.x, -size.y, 2 * size.x, 2 * size.y};
                if (rect.contains(newPos))
                    sprite.setPosition(newPos);
                else Die();
            }

        private:
            Cosmo::Utils::Trajectory trajectory;
        };
    }
}
