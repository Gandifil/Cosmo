#pragma once
#include <SFML\\Graphics.hpp>
#include <iostream>

namespace Cosmo
{
	namespace Entity
	{
		class ISpriteOwner: public sf::Drawable
		{
		public:
			ISpriteOwner(const sf::Texture& texture, const sf::Vector2f& pos)
			{
			    shader = nullptr;
				sprite.setTexture(texture);
				sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
				sprite.setPosition(pos);
			}

			virtual void draw(sf::RenderTarget &wnd, sf::RenderStates states) const override
			{
				if (shader) states.shader = shader;
				wnd.draw(sprite, states);
			}

			inline const sf::Vector2f& getPosition() const
			{
				return sprite.getPosition();
			}

		protected:
			sf::Sprite sprite;
            sf::Shader* shader;
		};
	}
}