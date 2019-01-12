#pragma once
#include <SFML\\System.hpp>

namespace Cosmo
{
	namespace Entity
	{
		class GameEntity
		{
		private:
			bool dead = false;

		protected:
			void Die() { dead = true; }

		public:
			GameEntity(){}

			inline bool isDead() { return dead; }

			virtual void Update(sf::Time dt) {};
		};
	}
}