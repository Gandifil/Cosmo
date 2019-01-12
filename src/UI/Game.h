#pragma once
#include "Scene.h"
#include "../Control/Keyboard.h"
#include "../Entity/Cruiser.h"
#include "../Control/Service.h"
#include "../Entity/Service.h"
#include <forward_list>
#include <string>

using namespace Cosmo;

namespace Cosmo
{
	namespace UI {
		class Game : public Scene {
		private:
			Control::Service controlling;
			Control::Keyboard kb;
			sf::RenderWindow &renderWindow;
			Entity::Cruiser *player, pl1;
			Entity::Service entities;

		public:
			Game(sf::RenderWindow &renderWindow);

			virtual int HandleEvent(sf::Event event) override;

			virtual void Update(sf::Time dt) override;

			virtual void Render() override;

			~Game();
		};
	}
}
