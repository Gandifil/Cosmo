#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <random>

namespace Cosmo
{
	namespace UI
	{
		class StarField: public sf::Drawable
		{
		public:
			StarField(sf::RenderWindow const &wnd);
			~StarField();
			virtual void draw(sf::RenderTarget &wnd, sf::RenderStates states) const;
			void Update(sf::Time dt);
		private:
			sf::Sprite sprite;
			sf::Texture texture;
			sf::Shader shader;
		};
	}
}
