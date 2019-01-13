#include "Cruiser.h"

using namespace Cosmo::Info;

void Cosmo::Entity::Cruiser::Move(sf::Time dt, Cosmo::Control::Direction d)
{
	sf::View view;
	auto winSize = view.getSize();
	auto myPos = sprite.getPosition();

	sf::Vector2f shift{
		float((d.dirs.right? speed.values[2]:0) - (d.dirs.left? speed.values[2]:0)) ,
		float((d.dirs.down? speed.values[1]:0) - (d.dirs.top? speed.values[0]:0)) };
	shift *= dt.asSeconds();

	sprite.move(shift);
}

void Cosmo::Entity::Cruiser::MainShoot()
{
	auto pos = sprite.getPosition();

	leftGun.Fire(pos);
	rightGun.Fire(pos);
}

void Cosmo::Entity::Cruiser::Update(sf::Time dt)
{
	leftGun.Update(dt);
	rightGun.Update(dt);
}
