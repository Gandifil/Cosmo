//
// Created by Gandifil on 06.07.2020.
//

#ifndef COSMO_ANIMATIONS_H
#define COSMO_ANIMATIONS_H

#include <cstdint>
#include <SFML/Graphics.hpp>
#include "../IUpdatable.h"

namespace Cosmo::UI {
    class Animation: public sf::Sprite, public IUpdatable {
    public:
        Animation(const sf::Texture& texture, unsigned int frameCount):
            frameTime{ 0.125 }, sf::Sprite{ texture } {
            auto size = texture.getSize();
            rect.left = 0;
            rect.top = 0;
            rect.width = size.x / frameCount;
            rect.height = size.y;
            setTextureRect(rect);
        }

        inline void start() noexcept {
            enabled = true;
        }

        inline void stop() noexcept {
            enabled = false;
        }

        inline void toFrame(int index) noexcept {
            rect.left = index * rect.width;
            setTextureRect(rect);
        }

        inline void nextFrame() noexcept {
            rect.left += rect.width;
            if (rect.left >= getTexture()->getSize().x)
                rect.left = 0;
            setTextureRect(rect);
        }

        virtual void update(sf::Time dt) override {
            if (enabled) {
                time += dt.asSeconds();
                if (time > frameTime) {
                    time -= frameTime;
                    nextFrame();
                }
            }
        }

    private:
        sf::IntRect rect;
        float frameTime, time = 0;
        bool enabled = true;
    };
};


#endif //COSMO_ANIMATIONS_H
