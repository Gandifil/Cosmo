#pragma once
#include "Scene.h"
#include "../Control/ConcreteControllers/Keyboard.h"
#include "../Entities/Cruiser.h"
#include "../Control/System.h"
#include "../Info/Manager.h"
#include "../Entities/GameDirector.h"
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
                    cruiser = Entities::Container::instance()
                            .addPlayer<Entity::Cruiser>(sf::Vector2f{500, 500}, m.Cruisers["first"]);
                    controlInit1 = new Control::Keyboard{*cruiser};
                }

		        Entity::Cruiser *cruiser;
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
