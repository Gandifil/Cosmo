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
        public:
            Controller(IControllable &actor1) : actor{ actor1 } {}
            virtual bool onHandleEvent(sf::Event event) = 0;
            virtual void ControlUpdate(sf::Time dt) = 0;

		protected:
			IControllable &actor;
		};
	}
}