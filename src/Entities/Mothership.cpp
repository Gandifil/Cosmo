#include "Mothership.h"

void Cosmo::Entities::Mothership::Move(sf::Time dt, Cosmo::Control::Directions d) {
    constexpr static auto angularVelocity = 20;
    static float angle = 0;
    angle += ((d.right? angularVelocity:0) - (d.left? angularVelocity:0))*dt.asSeconds();
    cannon.setRotation(angle);
}

void Cosmo::Entities::Mothership::mainShoot() {
    auto dir = Cosmo::Utils::ExtendedVector<float>::fromDegrees(cannon.getRotation() - 90.);
    gun.TryFire(position(), dir);
}

void Cosmo::Entities::Mothership::update(sf::Time dt) {
    gun.Update(dt);

    static sf::Clock clock;
   //cruiserShader.setUniform("time", clock.getElapsedTime().asSeconds());
    Move(dt, directions);
}


