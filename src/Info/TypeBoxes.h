//
// Created by Gandifil on 1/13/2019.
//

#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <sol.hpp>

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


        struct BulletBox
        {
            BulletBox(const TextureBox& tbox,
                      int trjNum,
                      float speed):
                    texture{tbox.texture},
                    trajectoryNum{trjNum},
                    speed{speed}{}

            const sf::Texture& texture;
            int trajectoryNum;
            float speed;
        };

        struct WeaponBox
        {
            WeaponBox(const BulletBox& bbox, float reload, const VectorBox& shift, const VectorBox& dir):
                reload{reload},
                shift{shift.vector},
                direction{dir.vector},
                bulletBox{bbox}{}

            BulletBox bulletBox;
            float reload;
            sf::Vector2f shift, direction;
        };

        struct StarshipBox
        {
            StarshipBox(const TextureBox& tbox,
                        const SpeedBox& sbox,
                        int maxhp,
                        sol::variadic_args va);

            const sf::Texture& texture;
            int maxHP;
            SpeedBox speed;
            std::vector<WeaponBox> weapons;
        };
    }
}