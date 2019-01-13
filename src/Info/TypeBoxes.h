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
            SpeedBox(int top, int down, int side): top{top}, down{down}, side{side}{}
            int top, down, side;
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
                direction{dir.vector}{}

            float reload;
            sf::Vector2f shift, direction;
        };

        struct StarshipBox
        {
            StarshipBox(const TextureBox& tbox,
                        const SpeedBox& sbox,
                        int maxhp):
                texture{tbox.texture},
                maxHP{maxhp},
                speed{sbox}
            {};

            const sf::Texture& texture;
            int maxHP;
            SpeedBox speed;
        };

        struct CruiserBox
        {
            CruiserBox(const StarshipBox& ssbox,
                       const WeaponBox& leftWeap,
                       const WeaponBox& rightWeap);

            WeaponBox leftWeapon, rightWeapon;
            StarshipBox starshipBox;
        };
    }
}