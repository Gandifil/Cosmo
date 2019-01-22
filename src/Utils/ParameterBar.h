//
// Created by Gandifil on 1/20/2019.
//

#ifndef COSMO_PARAMETERBAR_H
#define COSMO_PARAMETERBAR_H

#include <SFML/Graphics.hpp>

namespace Cosmo
{
    namespace Utils
    {
        class ParameterBar: public sf::Drawable
        {
        public:
            ParameterBar(sf::Color color, const sf::Vector2f& pos, float width, float height)
            :color{color}, rect{sf::Quads, 4}, width{width}
            {
                width /= 2; height /= 2;
// define the position of the triangle's points
                rect[0].position = pos + sf::Vector2f{-width, height};
                rect[1].position = pos + sf::Vector2f{-width + 10, -height};
                rect[2].position = pos + sf::Vector2f{width - 10, -height};
                rect[3].position = pos + sf::Vector2f{width, height};

// define the color of the triangle's points
                rect[0].color = color;
                rect[1].color = color;
                rect[2].color = color;
                rect[3].color = color;

                drawRect = rect;
            }

            inline void setValue(float param, float maxParam )
            {
                value = param / maxParam;
                drawRect[2].position.x = drawRect[1].position.x + value*(rect[2].position - rect[1].position).x;
                drawRect[3].position.x = drawRect[0].position.x + value*width;
            }

            virtual void draw(sf::RenderTarget &wnd, sf::RenderStates states) const override
            {
                wnd.draw(drawRect, states);
            }

        private:
            sf::Color color;
            sf::VertexArray rect, drawRect;

            float value;
            float width;
        };
    }
}
#endif //COSMO_PARAMETERBAR_H
