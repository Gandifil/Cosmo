//
// Created by Gandifil on 26.07.2020.
//

#ifndef COSMO_MOTHERSHIP_H
#define COSMO_MOTHERSHIP_H

#include "Starship.h"
#include "../Control/IControllable.h"
#include "../Utils/Weapon.h"
#include "../UI/Animation.h"

namespace Cosmo::Entities{
    class Mothership final : public Entities::Starship, public Cosmo::Control::IControllable {
    public:

        Mothership(const sf::Vector2f &vec, const Info::CruiserBox& box) :
                Starship{vec, box.starshipBox},
                gun{box.leftWeapon, true},
                cannon{ Info::Manager::Instance().Textures["core_cannon.png"], 11}
        {
            cannon.stop();
            auto size = cannon.getTextureRect();
            cannon.setOrigin(size.width/ 2.,  9 * size.height/ 8.);
            cannon.setPosition(position());
        }

        virtual ~ Mothership() override {}

        virtual void MainShoot() override;

        virtual void AltShoot() override {}

        virtual void MainAbility() override {}

        virtual void AltAbility() override {}

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
