#pragma once
#include "ISpriteOwner.h"
#include "IDestroyable.h"
#include "../Info/TypeBoxes.h"
#include "IHPOwner.h"
#include "../IUpdatable.h"

namespace Cosmo
{
	namespace Entity {
		class Starship : public IHPOwner, public ISpriteOwner, public IUpdatable {
		public:
			Starship(const sf::Vector2f &vec, const Info::StarshipBox& box) :
					ISpriteOwner{box.texture, vec},
					IHPOwner{box.maxHP},
					speed{box.speed}{}


			inline bool isCollised(const ISpriteOwner& entity)
            {
			    return sprite.getGlobalBounds().contains(entity.getPosition());
            }

		protected:
			Info::SpeedBox speed;
		};
	}
}

