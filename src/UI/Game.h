#pragma once
#include "Scene.h"
#include "../Control/ConcreteControllers/Keyboard.h"
#include "../Entities/Cruiser.h"
#include "../Control/System.h"
#include "../Info/Manager.h"
#include "../Entities/GameDirector.h"
#include "../Utils/HPBar.h"
#include "../Entities/Mothership.h"
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
                    sf::Vector2f point{800, 640};
                    auto player = Entities::Container::instance().addPlayer<Entities::Mothership>(point, m.Cruisers["second"]);
                    controlInit1 = new Control::Keyboard{*player};
                    cruiser = player;
                }

		        Entities::Starship *cruiser;
		        Control::IController *controlInit1, *controlInit2;
            };

            Game(sf::RenderWindow &renderWindow, const Parameters& params);

			explicit Game(sf::RenderWindow &renderWindow): Game{renderWindow, Parameters()} {};

            virtual bool handleEvent(sf::Event event) noexcept override;

            virtual void update(sf::Time dt) override;

            virtual void draw(sf::RenderTarget &wnd, sf::RenderStates states) const noexcept override;

		private:
            sf::RenderWindow &renderWindow;
			Control::System controlling;
			Entity::GameDirector gameDirector;
			Utils::HPBar hpBar;
		};
	}
}
