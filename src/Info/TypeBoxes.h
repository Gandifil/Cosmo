//
// Created by Gandifil on 1/13/2019.
//

#pragma once

#include <SFML/Graphics/Texture.hpp>

namespace Cosmo
{
    namespace Info
    {
        struct SpeedBox
        {
            SpeedBox(int top, int down, int side): values{top, down, side}{}
            int values[3];
        };

        struct TextureBox
        {
            TextureBox(const std::string& name);

            const sf::Texture& texture;
        };

        struct VectorBox
        {
            VectorBox(float x, float y):
                    vector{ x, y} {}

            const sf::Vector2f vector;
        };

        struct WeaponBox
        {
            WeaponBox(float reload, const VectorBox& shift, const VectorBox& dir):
                reload{reload},
                shift{shift.vector},
                direction{shift.vector}{}

            float reload;
            sf::Vector2f shift, direction;
        };

        struct CruiserBox
        {
            CruiserBox(const TextureBox& tbox,
                       const WeaponBox& leftWeap,
                       const WeaponBox& rightWeap,
                       const SpeedBox& sbox);

            TextureBox texture;
            WeaponBox leftWeapon, rightWeapon;
            SpeedBox speed;
        };
    }
}