#pragma once
#include <SFML\System.hpp>

namespace Cosmo
{
	namespace Control {

		/// <summary>
		///  This union keep a data about pressed buttons on controller.
		/// </summary>
		struct Directions {
			int top : 1;
			int down : 1;
			int left : 1;
			int right : 1;
		};

		/// <summary>
		///  Interface for game object which may be under control by player.
		/// </summary>
		class IControllable
		{
		public:
			virtual void MainShoot() = 0;
			virtual void AltShoot() = 0;
			virtual void MainAbility() = 0;
			virtual void AltAbility() = 0;

			Directions directions;
		};
	}
}