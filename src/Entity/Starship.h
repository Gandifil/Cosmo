#pragma once
#include "ISpriteOwner.h"
#include "IDestroyable.h"
#include "IUpdateable.h"

namespace Cosmo
{
	namespace Entity {
		class Starship : public IDestroyable, public ISpriteOwner, public IUpdateable {
		public:
			Starship(int maxHP, const sf::Texture &texture, const sf::Vector2f &vec) :
					ISpriteOwner{texture, vec},
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

		private:
			int hp;
		};
	}
}

