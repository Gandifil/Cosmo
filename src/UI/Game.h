#pragma once
#include "Scene.h"
#include "../Control/Keyboard.h"
#include "../Entity/Cruiser.h"
#include "../Control/Service.h"
#include "../Entity/Service.h"
#include "../Info/Manager.h"
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
                    cruiser = new Cruiser{100, m.Cruisers["first"].texture.texture, {500, 500} };
                    controlInit = new Control::Keyboard{*cruiser};
                }

		        Entity::Cruiser *cruiser;
		        Control::Controller *controlInit;
            };

            Game(sf::RenderWindow &renderWindow, const Parameters& params);

			explicit Game(sf::RenderWindow &renderWindow): Game{renderWindow, Parameters()} {};

            virtual int HandleEvent(sf::Event event) override;

            virtual void Update(sf::Time dt) override;

            virtual void Render() override;

            ~Game();

		private:
            sf::RenderWindow &renderWindow;
			Control::Service controlling;
			Entity::Service entities;

		};
	}
}
