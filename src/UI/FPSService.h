//
// Created by Gandifil on 1/17/2019.
//

#ifndef COSMO_FPSSERVICE_H
#define COSMO_FPSSERVICE_H

#include <SFML/Graphics.hpp>

namespace Cosmo
{
    namespace UI
    {
    class FPSService final: public sf::Drawable, public IUpdatable
        {
        public:
            FPSService()
            {
                font.loadFromFile("verdana.ttf");
                text.setFillColor(sf::Color::Red);
                text.setFont(font);
            }

            inline void update(sf::Time dt)
            {
                fps = 1.f / dt.asSeconds();
                text.setString("FPS: " + std::to_string(fps));
            }

            inline virtual void draw(sf::RenderTarget &wnd, sf::RenderStates states) const override
            {
                wnd.draw(text);
            }

        private:
            float fps;
            sf::Font font;
            sf::Text text;
        };
    }
}

#endif //COSMO_FPSSERVICE_H
