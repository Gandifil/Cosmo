//
// Created by Gandifil on 27.01.2020.
//

#ifndef COSMO_ENTITYSPRITE_H
#define COSMO_ENTITYSPRITE_H

#include <SFML\\Graphics.hpp>

namespace Cosmo::Entities {
    class EntitySprite: public sf::Sprite {
    public:
        EntitySprite(const sf::Texture& texture, const sf::Vector2f& pos)
        {
            shader = nullptr;
            setTexture(texture);
            setOrigin(getLocalBounds().width / 2, getLocalBounds().height / 2);
            setPosition(pos);
        }

        void drawUsingShader(sf::RenderTarget &wnd, sf::RenderStates states) const
        {
            if (shader) states.shader = shader;
            wnd.draw(*this, states);
        }

        sf::Shader* shader;
    };
}

#endif // COSMO_ENTITYSPRITE_H