#pragma once
#include "EntitySprite.h"
#include "IEntity.h"
#include "../Info/TypeBoxes.h"
#include "IHasHealthPoints.h"

namespace Cosmo::Entities {
    class Starship : public IEntity, public IHasHealthPoints {
    public:
        Starship(const sf::Vector2f &vec, const Info::StarshipBox& box) :
                IHasHealthPoints{box.maxHP },
                sprite{ box.texture, vec },
                speed{ box.speed }{}


        inline virtual void colliseWith(const IEntity* entity) noexcept override {
            damage(100);
            if (HP() <= 0)
                Die();
        }

        inline bool isColliseWith(const IEntity *entity) const noexcept override {
            return sprite.getGlobalBounds().contains(entity->position());
        }

        inline virtual const sf::Vector2f& position() const noexcept override{
            return sprite.getPosition();
        }

    protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
            sprite.drawUsingShader(target, states);
        }

        EntitySprite sprite;
        Info::SpeedBox speed;
    };
}

