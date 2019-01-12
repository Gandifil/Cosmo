#pragma once
#include "Controller.h"

namespace Cosmo
{
	namespace Control {
		class Keyboard : public Controller {
		public:
			Keyboard(IControllable &actor) : Controller(actor) {
				shoot1 = sf::Keyboard::Space;
				shoot2 = sf::Keyboard::LControl;
				abil1 = sf::Keyboard::RShift;
				abil2 = sf::Keyboard::RControl;

				top = sf::Keyboard::W;
				down = sf::Keyboard::S;
				left = sf::Keyboard::A;
				right = sf::Keyboard::D;
			}

			sf::Keyboard::Key shoot1, shoot2, abil1, abil2;
			sf::Keyboard::Key top, down, left, right;

			virtual bool onHandleEvent(sf::Event event) override {
				if (event.type == sf::Event::EventType::KeyReleased) {
					if (event.key.code == shoot1) actor.MainShoot();
					else if (event.key.code == shoot2) actor.AltShoot();
					else if (event.key.code == abil1) actor.MainAbility();
					else if (event.key.code == abil2) actor.AltAbility();
					else return false;
				} else return false;

				return false;
			}

			virtual void ControlUpdate(sf::Time dt) override {
				Direction buf;
				buf.value = 0;
				buf.dirs.top = sf::Keyboard::isKeyPressed(top);
				buf.dirs.down = sf::Keyboard::isKeyPressed(down);
				buf.dirs.left = sf::Keyboard::isKeyPressed(left);
				buf.dirs.right = sf::Keyboard::isKeyPressed(right);
				if (buf.value) actor.Move(dt, buf);
			}
		};
	}
}
