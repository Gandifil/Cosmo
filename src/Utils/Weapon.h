//
// Created by Gandifil on 1/12/2019.
//

#ifndef COSMO_WEAPON_H
#define COSMO_WEAPON_H

#include <tgui/Vector2.hpp>
#include <sol/sol.hpp>
#include "../Entities/Container.h"
#include "../Entities/Bullet.h"
#include "../Entities/Starship.h"

namespace Cosmo::Utils {
    class Weapon: public IUpdatable {
    public:
        struct Parameters {
            Parameters(const sol::table& lua):
                bullet{ lua["bullet"].get<sol::table>() } {
                reload = lua.get_or("reload", 1.);
                degrees = lua.get_or("degrees", 1.);
                auto positiont = lua["position"];
                position.x = positiont["x"].get<float>();
                position.y = positiont["y"].get<float>();
            }

            const Entities::Bullet::Parameters bullet;
            float reload;
            float degrees;
            sf::Vector2f position;
        };

        explicit Weapon(const Parameters& parameters, const Entities::Starship& owner):
                t{0}, reloadTime{parameters.reload},
                position{ parameters.position },
                owner{ owner },
                bullet{parameters.bullet}
        {
            setRotation(parameters.degrees);
        }

        inline void update(sf::Time dt) override {
            if (t > 0) t-= dt.asSeconds();
        }

        inline bool isReady() const noexcept {
            return t <= 0;
        }

        inline bool tryFire() noexcept {
            if (isReady()) {
                fire();
                return true;
            }
            return false;
        }

        inline bool fireAlways(sf::Time dt) {
            update(dt);
            return tryFire();
        }

        inline void setRotation(float degrees) noexcept {
            dir = Cosmo::Utils::ExtendedVector<float>::fromDegrees(degrees);
        }
    private:

        inline void fire() {
            t = reloadTime;

            Entities::Container::instance().add<Entities::Bullet>(
                    bullet,
                    owner.team(),
                    owner.position() + position,
                    dir);
        }

        const Entities::Bullet::Parameters bullet;
        const Entities::Starship& owner;
        sf::Vector2f position;
        sf::Vector2f dir;
        float t, reloadTime;
    };
}

#endif // COSMO_WEAPON_H