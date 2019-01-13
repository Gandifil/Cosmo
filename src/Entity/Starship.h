#pragma once
#include "ISpriteOwner.h"
#include "IDestroyable.h"
#include "IUpdateable.h"
#include "../Info/TypeBoxes.h"

namespace Cosmo
{
	namespace Entity {
		class Starship : public IDestroyable, public ISpriteOwner, public IUpdateable {
		public:
			Starship(const sf::Vector2f &vec, const Info::StarshipBox& box) :
					ISpriteOwner{box.texture, vec},
					hp{box.maxHP},
					speed{box.speed}{}

			inline int getHP() { return hp; }

			inline void Damage(unsigned int value) {
				hp -= value;
				if (hp <= 0) Die();
			}

			inline void Repair(unsigned int value) {
				hp += value;
				// if (type.maxHP < hp) hp = type.maxHP;
			}

		protected:
			Info::SpeedBox speed;

		private:
			int hp;
		};
	}
}

