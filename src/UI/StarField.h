//
// Created by Gandifil on 24.01.2020.
//

#ifndef COSMO_UI_STARFIELD
#define COSMO_UI_STARFIELD

#include <SFML/Graphics.hpp>
#include <vector>
#include <random>
#include "../IUpdatable.h"

namespace Cosmo::UI {
	class StarField: public sf::Drawable, public IUpdatable {
	public:
		StarField(sf::RenderWindow const &wnd);
		inline virtual void draw(sf::RenderTarget &wnd, sf::RenderStates states) const;
		inline void update(sf::Time dt) override;

	private:
		sf::Sprite sprite;
		sf::Texture texture;
		sf::Shader shader;
	};

	StarField::StarField(sf::RenderWindow const &wnd)
	{
		auto winSize = wnd.getSize();

		if (!shader.loadFromFile("space.frag", sf::Shader::Fragment))
		{
		}

		texture.create(winSize.x, winSize.y);
		sprite.setTexture(texture);
	}

	inline void StarField::draw(sf::RenderTarget &wnd, sf::RenderStates states) const
	{
		wnd.draw(sprite, &shader);
	}

	inline void StarField::update(sf::Time dt)
	{
		static float time = 0;
		time += dt.asSeconds();
		shader.setUniform("time", time);
	}
}

#endif