#pragma once
#include <vector>
#include <assert.h>
#include "Controller.h"

namespace Cosmo
{
	namespace Control {
		class Service {
		public:
			Service(std::initializer_list<Controller *> init_list) : controllers{init_list} { }

			bool onHandleEvent(sf::Event event) {
				for (auto item : controllers)
					if (item->onHandleEvent(event))
						return true;
				return false;
			}

			void Update(sf::Time dt) {
				for (auto item : controllers)
					item->ControlUpdate(dt);
			}

		private:
			std::vector<Controller *> controllers;
		};
	}
}