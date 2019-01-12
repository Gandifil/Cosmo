#pragma once
#include <SFML\System.hpp>

namespace Cosmo
{
	namespace Control {
		/// <summary>
		///  This union keep a data about pressed buttons on controller.
		/// </summary>
		union Direction {
			struct Dir {
				int top : 1;
				int down : 1;
				int left : 1;
				int right : 1;
			} dirs;
			unsigned short value;
		};

		/// <summary>
		///  Interface for game object which may be under control by players.
		/// </summary>
		class IControllable
		{
		public:
			virtual ~IControllable() {};
			virtual void Move(sf::Time dt, Direction dir) = 0;
			virtual void MainShoot() = 0;
			virtual void AltShoot() = 0;
			virtual void MainAbility() = 0;
			virtual void AltAbility() = 0;
		};
	}
}