#pragma once
#include "Drawable.h"

namespace Cosmo
{
	namespace Entity {
		class Starship : public Drawable {
		private:
			int hp;

		public:
			Starship(int maxHP, const sf::Texture &texture, const sf::Vector2f &vec) :
					Drawable{texture, vec},
					hp{maxHP} {}

			inline int getHP() { return hp; }

			inline void Damage(unsigned int value) {
				hp -= value;
				if (hp <= 0) Die();
			}

			inline void Repair(unsigned int value) {
				hp += value;
				// if (type.maxHP < hp) hp = type.maxHP;
			}
		};
	}
}

