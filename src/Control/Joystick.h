//
// Created by Gandifil on 1/12/2019.
//
#pragma once
#include "Controller.h"

namespace Cosmo
{
    namespace Control {
        class Joystick : public Controller {
        public:
            enum {
                DPAD_UP       = 0x0001,
                DPAD_DOWN = 0x0002,
                DPAD_LEFT    = 0x0004,
                DPAD_RIGHT  = 0x0008,
                START            = 0x0010,
                BACK              = 0x0020,
                LEFT_THUMB   = 0x0040,
                RIGHT_THUMB = 0x0080,
                LB                   = 0x0100,
                RB                  = 0x0200,
                A                   = 0x1000,
                B                  = 0x2000,
                X                  = 0x4000,
                Y                  = 0x8000,
            };

            Joystick(IControllable &actor, int n) : Controller(actor), n(n) {
                shoot1 = 4;
                shoot2 = 5;
                abil1 = 8;
                abil2 = 9;

                top = 3;
                down = 0;
                left = 2;
                right = 1;
            }

            int shoot1, shoot2, abil1, abil2;
            int top, down, left, right;

            virtual bool onHandleEvent(sf::Event event) override {
                return false;
            }

            virtual void ControlUpdate(sf::Time dt) override {
                Direction buf;
                buf.value = 0;
                buf.dirs.top = sf::Joystick::isButtonPressed(n, top);
                buf.dirs.down = sf::Joystick::isButtonPressed(n, down);
                buf.dirs.left = sf::Joystick::isButtonPressed(n, left);
                buf.dirs.right = sf::Joystick::isButtonPressed(n, right);
                if (buf.value) actor.Move(dt, buf);

                if (sf::Joystick::isButtonPressed(n, shoot1))
                    actor.MainShoot();
                if (sf::Joystick::isButtonPressed(n, shoot2))
                    actor.AltShoot();
                if (sf::Joystick::isButtonPressed(n, abil1))
                    actor.MainAbility();
                if (sf::Joystick::isButtonPressed(n, abil2))
                    actor.AltAbility();
            }

        private:
            int n;
        };
    }
}
