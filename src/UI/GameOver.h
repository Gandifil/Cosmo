//
// Created by Gandifil on 1/25/2019.
//

#ifndef COSMO_GAMEOVER_H
#define COSMO_GAMEOVER_H

#include "Menu.h"

namespace Cosmo
{
    namespace UI
    {
        class GameOver final: public Menu
        {
        public:
            struct Statistics
            {
                int points;
            };

            GameOver(sf::RenderWindow &wnd, const Statistics& stats);

            int HandleEvent(sf::Event event) override;
//            virtual int HandleEvent(sf::Event event) override {
//                Menu::HandleEvent(event);
//                return (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) ? 0 : 1;
//            }

        private:
            tgui::Label::Ptr label, underLabel;
        };
    }
}


#endif //COSMO_GAMEOVER_H
