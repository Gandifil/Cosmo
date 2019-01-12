#pragma once
#include <SFML\\Graphics.hpp>
#include "GameEntity.h"

namespace Cosmo
{
	namespace Entity
	{
		class Drawable: public GameEntity, public sf::Drawable
		{
		protected:
			sf::Sprite sprite;

		public:
			Drawable(const sf::Texture& texture, const sf::Vector2f& pos)
			{
				sprite.setTexture(texture);
				sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
				sprite.setPosition(pos);
			}

			virtual void draw(sf::RenderTarget &wnd, sf::RenderStates states) const override
			{
				wnd.draw(sprite, states);
			}
		};
	}
}