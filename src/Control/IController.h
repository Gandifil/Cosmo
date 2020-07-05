//
// Created by Gandifil on 25.01.2020.
//

#ifndef COSMO_CONTROL_CONTROLLER
#define COSMO_CONTROL_CONTROLLER

#include "IControllable.h"
#include "../IEventHandler.h"

namespace Cosmo::Control {
	class IController: public IEventHandler {
	public:
		IController(IControllable &actor) noexcept : actor{ actor } {}

	protected:
		IControllable &actor;
	};
}

#endif // COSMO_CONTROL_CONTROLLER