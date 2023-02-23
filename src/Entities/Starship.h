#pragma once
#include "EntitySprite.h"
#include <sol/sol.hpp>
#include "IEntity.h"
#include "IHasHealthPoints.h"
#include "../Info/ResourcesStorage.h"

namespace Cosmo::Entities {
    class Starship : public IEntity, public IHasHealthPoints {
    public:
        struct Parameters {
            Parameters(const sol::table& lua):
                texture{Info::ResourcesStorage::get<sf::Texture>(lua["texture"])} {
                maxHP = lua.get_or("maxHP", 1000);
                up = lua.get_or("up", 0);
                down = lua.get_or("down", 0);
                side = lua.get_or("side", 0);
            }

            const sf::Texture& texture;
            int maxHP;
            int up, down, side;
        };

        Starship(const Parameters& parameters, const sf::Vector2f &vec) :
                IHasHealthPoints{parameters.maxHP },
                sprite{ parameters.texture, vec },
                parameters{ parameters }{}


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
        const Parameters parameters;
    };
}

