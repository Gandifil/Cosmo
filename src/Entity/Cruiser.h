#pragma once
#include "Starship.h"
#include "../Control/IControllable.h"
#include "../Utils/DirectedWeapon.h"

namespace Cosmo
{
	namespace Entity {
	    class Cruiser final : public Starship, public Cosmo::Control::IControllable {
		public:

            Cruiser(const sf::Vector2f &vec, const Info::CruiserBox& box) :
                    Starship{vec, box.starshipBox},
                    leftGun{box.leftWeapon, true},
                    rightGun{box.rightWeapon, true}
			{
                if (cruiserShader.loadFromFile("water.frag", sf::Shader::Fragment))
                {
                    shader = &cruiserShader;
                }

			}

			virtual ~ Cruiser() override {}

			virtual void MainShoot() override;

			virtual void AltShoot() override {}

			virtual void MainAbility() override {}

			virtual void AltAbility() override {}

			inline void Move(sf::Time dt, Cosmo::Control::Directions d);

			virtual void update(sf::Time dt) override;

	    private:
	        Utils::DirectedWeapon leftGun, rightGun;
	        sf::Shader cruiserShader;
		};
	}
}

