#pragma once

#include <assert.h>
#include "SFML/Window.hpp"
#include "IControllable.h"

namespace Cosmo
{
	namespace Control
	{
		class Controller
		{
		protected:
			IControllable &actor;

		public:
			Controller(IControllable &actor) : actor{ actor } {
				assert(&actor != nullptr);
			}
			virtual bool onHandleEvent(sf::Event event) = 0;
			virtual void ControlUpdate(sf::Time dt) = 0;
		};
	}
}