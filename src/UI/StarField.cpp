#include "StarField.h"

using namespace Cosmo::UI;

StarField::StarField(sf::RenderWindow const &wnd)
{
	winSize = wnd.getSize();

	int countStars = (winSize.x * winSize.y) / 1000 * spb;
	stars.resize(countStars);
	for (size_t i = 0; i < countStars; i++)
	{
		stars[i] = sf::Vector2f(rand()%winSize.x, rand() % winSize.y);
	}
}

StarField::~StarField()
{
}

void StarField::draw(sf::RenderTarget &wnd, sf::RenderStates states) const
{
	wnd.clear(sf::Color::Black);
	sf::Vertex buf({0, 0}, sf::Color::White);
	for (size_t i = 0; i < stars.size(); i++)
	{
		buf.position = stars[i];
		wnd.draw(&buf, 1, sf::PrimitiveType::Points);
	}
}

void StarField::Update(sf::Time dt)
{
	sf::Vector2f sp(0, speed * dt.asSeconds());
	for (size_t i = 0; i < stars.size(); i++)
	{
		stars[i] += sp;
		if (stars[i].y > winSize.y)
			stars[i] = sf::Vector2f(rand() % winSize.x, 0);
	}
}