#pragma once
#include "Starship.h"
#include "../Control/IControllable.h"
#include "../Utils/Weapon.h"

namespace Cosmo
{
	namespace Entity {
	    class Cruiser final : public Entities::Starship, public Cosmo::Control::IControllable {
		public:
	        struct Parameters : public Entities::Starship::Parameters {
                Parameters(const sol::table& lua):
                        Entities::Starship::Parameters{ lua },
                        leftWeapon{ lua["leftWeapon"].get<sol::table>() } ,
                        rightWeapon{ lua["rightWeapon"].get<sol::table>() }
                {}

                Utils::Weapon::Parameters leftWeapon;
                Utils::Weapon::Parameters rightWeapon;
            };

            Cruiser(const Parameters& parameters, const sf::Vector2f &vec) :
                    Starship{parameters, vec},
                    leftGun{parameters.leftWeapon, *this},
                    rightGun{parameters.rightWeapon, *this}
			{
                if (cruiserShader.loadFromFile("water.frag", sf::Shader::Fragment))
                {
                    sprite.shader = &cruiserShader;
                }

			}

			virtual ~ Cruiser() override {}

			virtual void mainShoot() override;

			inline void Move(sf::Time dt, Cosmo::Control::Directions d);

			virtual void update(sf::Time dt) override;

            virtual int team() const noexcept {
                return 0;
            };

	    private:
	        Utils::Weapon leftGun, rightGun;
	        sf::Shader cruiserShader;
		};
	}
}

