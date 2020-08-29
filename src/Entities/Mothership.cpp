#include "Mothership.h"
#include <math.h>

using namespace Cosmo::Info;

void Cosmo::Entities::Mothership::Move(sf::Time dt, Cosmo::Control::Directions d) {
    constexpr static auto angularVelocity = 20;
    static float angle = 0;
    angle += ((d.right? angularVelocity:0) - (d.left? angularVelocity:0))*dt.asSeconds();
    cannon.setRotation(angle);
}

void Cosmo::Entities::Mothership::MainShoot() {
    auto angle = cannon.getRotation() * M_PI / 180.;
    const sf::Vector2f up{
        static_cast<float>(sin(angle)),
        -static_cast<float>(cos(angle))};
    gun.TryFire(sprite.getPosition(), up);
}

void Cosmo::Entities::Mothership::update(sf::Time dt) {
    gun.Update(dt);

    static sf::Clock clock;
   //cruiserShader.setUniform("time", clock.getElapsedTime().asSeconds());
    Move(dt, directions);
}


