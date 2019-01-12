#pragma once
#include "Starship.h"
#include "../Control/IControllable.h"
#include "../Utils/Weapon.h"

namespace Cosmo
{
	namespace Entity {
	    class Cruiser final : public Starship, public Cosmo::Control::IControllable {
		public:
			Cruiser(int maxHP, const sf::Texture &texture, const sf::Vector2f &vec) :
					Starship{maxHP, texture, vec},
					leftGun{sf::Vector2f{-10, 0}, sf::Vector2f{0, -100}, 0.25},
                    rightGun{sf::Vector2f{10, 0}, sf::Vector2f{0, -100}, 0.25}
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
		};
	}
}

