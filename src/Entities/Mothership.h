//
// Created by Gandifil on 26.07.2020.
//

#ifndef COSMO_MOTHERSHIP_H
#define COSMO_MOTHERSHIP_H

#include <sol/sol.hpp>
#include "Starship.h"
#include "../Control/IControllable.h"
#include "../Utils/Weapon.h"
#include "../UI/Animation.h"

namespace Cosmo::Entities{
    class Mothership final : public Starship, public Cosmo::Control::IControllable {
    public:
        struct Parameters : public Entities::Starship::Parameters {
            Parameters(const sol::table& lua):
                    Entities::Starship::Parameters{ lua },
                    cannon{Info::ResourcesStorage::get<sf::Texture>(lua["cannon"])},
                    weapon{ lua["weapon"].get<sol::table>() }{}

            Utils::Weapon::Parameters weapon;
            const sf::Texture& cannon;
        };

        Mothership(const Parameters& parameters, const sf::Vector2f &vec) :
                Starship{parameters, vec},
                gun{parameters.weapon, *this},
                cannon{ parameters.cannon, 11}
        {
            cannon.stop();
            auto size = cannon.getTextureRect();
            cannon.setOrigin(size.width/ 2.,  9 * size.height/ 8.);
            cannon.setPosition(position());
        }

        virtual ~ Mothership() override {}

        virtual void mainShoot() override;

        inline void Move(sf::Time dt, Cosmo::Control::Directions d);

        virtual void update(sf::Time dt) override;

        virtual int team() const noexcept {
            return 0;
        }

    protected:
        void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
            target.draw(cannon, states);
            sprite.drawUsingShader(target, states);
        }

    private:
        Utils::Weapon gun;
        UI::Animation cannon;
    };
}

#endif //COSMO_MOTHERSHIP_H
