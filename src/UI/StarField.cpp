#include <iostream>
#include "StarField.h"

using namespace Cosmo::UI;

StarField::StarField(sf::RenderWindow const &wnd)
{
	auto winSize = wnd.getSize();

	if (!shader.loadFromFile("space.frag", sf::Shader::Fragment))
	{
	}

	texture.create(winSize.x, winSize.y);
	sprite.setTexture(texture);
}

StarField::~StarField()
{
}

void StarField::draw(sf::RenderTarget &wnd, sf::RenderStates states) const
{
	wnd.draw(sprite, &shader);
}

void StarField::Update(sf::Time dt)
{
	static float time = 0;
	time += dt.asSeconds();
	shader.setUniform("time", time);
}