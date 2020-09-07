//
// Created by Gandifil on 1/13/2019.
//

#ifndef COSMO_SCOUT_H
#define COSMO_SCOUT_H

#include "../Starship.h"
#include "../../Utils/Weapon.h"

namespace Cosmo::Entities::Enemies{
    class Scout final : public Entities::Starship {
    public:
        struct Parameters : public Entities::Starship::Parameters {
            Parameters(const sol::table& lua);

            Utils::Weapon::Parameters weapon;
        };

        Scout(const Parameters& parameters, const sf::Vector2f& pos);

        void update(sf::Time dt) override;

        virtual int team() const noexcept {
            return 1;
        };

    private:
        sf::Vector2f dstPoint;
        Utils::Weapon weapon;
    };
}

#endif // COSMO_SCOUT_H