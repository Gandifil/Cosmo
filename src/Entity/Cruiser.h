#pragma once
#include "Starship.h"
#include "../Control/IControllable.h"
#include "../Utils/DirectedWeapon.h"

namespace Cosmo
{
	namespace Entity {
	    class Cruiser final : public Starship, public Cosmo::Control::IControllable {
		public:

            Cruiser(const sf::Vector2f &vec, const Info::StarshipBox& box) :
                    Starship{vec, box},
                    leftGun{box.weapons[0], true},
                    rightGun{box.weapons[1], true}
			{
				const Info::ShaderBox& shBox = Info::Manager::Instance().Get<Info::ShaderBox>("shJets");
				if (cruiserShader.loadFromMemory(shBox.getText(), sf::Shader::Fragment))
                {
                    shader = &cruiserShader;
                }

			}

			virtual ~ Cruiser() override {}

			virtual void MainShoot() override;

			virtual void AltShoot() override {}

			virtual void MainAbility() override {}

			virtual void AltAbility() override {}

			virtual void Move(sf::Time dt, Cosmo::Control::Direction d) override;

			virtual void Update(sf::Time dt) override;

	    private:
	        Utils::DirectedWeapon leftGun, rightGun;
	        sf::Shader cruiserShader;
		};
	}
}

