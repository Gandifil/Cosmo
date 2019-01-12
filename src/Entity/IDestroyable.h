#pragma once

namespace Cosmo
{
	namespace Entity
	{
		class IDestroyable
		{
		public:
			inline bool isDead() { return dead; }

		protected:
			void Die() { dead = true; }

		private:
			bool dead = false;
		};
	}
}