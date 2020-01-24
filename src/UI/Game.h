#pragma once
#include "Scene.h"
#include "../Control/Keyboard.h"
#include "../Entity/Cruiser.h"
#include "../Control/Service.h"
#include "../Entity/Service.h"
#include "../Info/Manager.h"
#include "../Entity/GameDirector.h"
#include "../Control/Joystick.h"
#include "../Utils/HPBar.h"
#include <forward_list>
#include <string>

using namespace Cosmo;

namespace Cosmo
{
	namespace UI {
		class Game : public Scene {
        public:
		    struct Parameters
            {
		        Parameters()
                {
					Info::Manager& m = Info::Manager::Instance();
					m.Loading();
                    cruiser = new Cruiser{{500, 500}, m.Cruisers["first"]};
                    controlInit1 = new Control::Keyboard{*cruiser};
					controlInit2 = new Control::Joystick{*cruiser, 0};
                }

		        Entity::Cruiser *cruiser;
		        Control::Controller *controlInit1, *controlInit2;
            };

            Game(sf::RenderWindow &renderWindow, const Parameters& params);

			explicit Game(sf::RenderWindow &renderWindow): Game{renderWindow, Parameters()} {};

            virtual void handleEvent(sf::Event event) override;

            virtual void update(sf::Time dt) override;

            virtual void Render() override;

		private:
            sf::RenderWindow &renderWindow;
			Control::Service controlling;
			Entity::GameDirector gameDirector;
			Entity::Service& entities;
			Utils::HPBar hpBar;
		};
	}
}
