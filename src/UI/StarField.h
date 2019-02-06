#pragma once
#include <SFML/Graphics.hpp>

namespace Cosmo
{
	namespace UI
	{
		class StarField: public sf::Drawable
		{
		public:
			StarField(sf::RenderWindow const &wnd);
			virtual void draw(sf::RenderTarget &wnd, sf::RenderStates states) const;
			void Update(sf::Time dt);

		private:
			sf::Sprite sprite;
			sf::Texture texture;
			sf::Shader shader;
		};
	}
}
