#pragma once
#include "Starship.h"
#include "../Control/IControllable.h"

namespace Cosmo
{
	namespace Entity {
	class Cruiser final : public Starship, public Cosmo::Control::IControllable {
		public:
			Cruiser(int maxHP, const sf::Texture &texture, const sf::Vector2f &vec) :
					Starship{maxHP, texture, vec} {}

			virtual ~ Cruiser() override {}

			virtual void MainShoot() override;

			virtual void AltShoot() override {}

			virtual void MainAbility() override {}

			virtual void AltAbility() override {}

			virtual void Move(sf::Time dt, Cosmo::Control::Direction d) override;
		};
	}
}

