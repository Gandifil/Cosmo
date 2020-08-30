#include "Mothership.h"

void Cosmo::Entities::Mothership::Move(sf::Time dt, Cosmo::Control::Directions d) {
    constexpr static auto angularVelocity = 20;
    auto angle = ((d.right? angularVelocity:0) - (d.left? angularVelocity:0))*dt.asSeconds();
    if (abs(angle) > 0.01){
        auto newAngle = cannon.getRotation() + angle;
        cannon.setRotation(newAngle);
        gun.setRotation(newAngle - 90);
    }
}

void Cosmo::Entities::Mothership::mainShoot() {
    gun.tryFire();
}

void Cosmo::Entities::Mothership::update(sf::Time dt) {
    gun.update(dt);

    Move(dt, directions);
}


