#include "Cruiser.h"
#include "../Info/Config.h"

using namespace Cosmo::Info;

void Cosmo::Entity::Cruiser::Move(sf::Time dt, Cosmo::Control::Direction d)
{
	static int w = Config::Instance().getParam(Config::ConfigParam::WWindow)
			 , h = Config::Instance().getParam(Config::ConfigParam::HWindow);
	auto myPos = sprite.getPosition();

	sf::Vector2f shift{ 0, 0 };
	float ms = dt.asSeconds();
	float speed = 200;
	if (d.dirs.right && (myPos.x <= w)) shift.x += speed * ms;
	if (d.dirs.left && (myPos.x >= 0)) shift.x -= speed  * ms;
	if (d.dirs.top && (myPos.y >= 0)) shift.y -= speed * ms;
	if (d.dirs.down && (myPos.y <= h)) shift.y += speed * ms;

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
