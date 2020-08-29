#include "Cruiser.h"

using namespace Cosmo::Info;

void Cosmo::Entity::Cruiser::Move(sf::Time dt, Cosmo::Control::Directions d)
{
	sf::View view;
	auto winSize = view.getSize();
	auto myPos = sprite.getPosition();

	sf::Vector2f shift{
		float((d.right? parameters.side:0) - (d.left? parameters.side:0)) ,
		float((d.down? parameters.down:0) - (d.top? parameters.up:0)) };
	shift *= dt.asSeconds();

	sprite.move(shift);
}

void Cosmo::Entity::Cruiser::mainShoot()
{
	auto pos = sprite.getPosition();

	leftGun.TryFire(pos);
	rightGun.TryFire(pos);
}

void Cosmo::Entity::Cruiser::update(sf::Time dt)
{
	leftGun.Update(dt);
	rightGun.Update(dt);

	static sf::Clock clock;
	cruiserShader.setUniform("time", clock.getElapsedTime().asSeconds());
	Move(dt, directions);
}


