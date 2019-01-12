#pragma once
#include <SFML\Graphics.hpp>

namespace Cosmo
{
	namespace Info
	{
		struct ReadTexture
		{
			sf::Texture* operator()(const std::string& index)
			{
				sf::Texture* texture = new sf::Texture{};
				texture->loadFromFile(index);
				return texture;
			}
		};
	}
}