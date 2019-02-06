#include "StarField.h"
#include "../Info/Manager.h"

using namespace Cosmo::UI;

StarField::StarField(sf::RenderWindow const &wnd)
{
	auto winSize = wnd.getSize();

	const Info::ShaderBox& box = Info::Manager::Instance().Get<Info::ShaderBox>("shSpace");
	if (!shader.loadFromMemory(box.getText(), sf::Shader::Fragment))
	{
	}

	texture.create(winSize.x, winSize.y);
	sprite.setTexture(texture);
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