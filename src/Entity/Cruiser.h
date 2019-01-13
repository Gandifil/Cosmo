#pragma once
#include "Starship.h"
#include "../Control/IControllable.h"
#include "../Utils/Weapon.h"

namespace Cosmo
{
	namespace Entity {
	    class Cruiser final : public Starship, public Cosmo::Control::IControllable {
		public:

            Cruiser(const sf::Vector2f &vec, const Info::CruiserBox& box) :
                    Starship{100, box.texture, vec},
                    leftGun{box.leftWeapon},
                    rightGun{box.rightWeapon},
                    speed{box.speed}
			{}

			virtual ~ Cruiser() override {}

			virtual void MainShoot() override;

			virtual void AltShoot() override {}

			virtual void MainAbility() override {}

			virtual void AltAbility() override {}

			virtual void Move(sf::Time dt, Cosmo::Control::Direction d) override;

			virtual void Update(sf::Time dt) override;

	    private:
	        Utils::Weapon leftGun, rightGun;
	        Info::SpeedBox speed;
		};
	}
}

