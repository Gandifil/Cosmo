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
			Controller(IControllable &actor) : actor{ actor } {}
            virtual bool onHandleEvent(sf::Event event) = 0;

		protected:
			IControllable &actor;
		};
	}
}