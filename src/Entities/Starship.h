#pragma once
#include "EntitySprite.h"
#include "IEntity.h"
#include "../Info/TypeBoxes.h"
#include "HealthPoints.h"

namespace Cosmo::Entities {
    class Starship : public IEntity {
    public:
        Starship(const sf::Vector2f &vec, const Info::StarshipBox& box) :
                hp{box.maxHP},
                sprite{box.texture, vec},
                speed{box.speed}{}

//
//        inline bool isCollised(const EntitySprite& entity)
//        {
//            return sprite.getGlobalBounds().contains(entity.getPosition());
//        }

    protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
            sprite.drawUsingShader(target, states);
        }

    public:

        inline const HealthPoints& getHP() const {
            return hp;
        }

        inline auto getPosition() const {
            return sprite.getPosition();
        }

    protected:
        HealthPoints hp;
        EntitySprite sprite;
        Info::SpeedBox speed;
    };
}

