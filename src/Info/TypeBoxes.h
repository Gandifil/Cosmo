//
// Created by Gandifil on 1/13/2019.
//

#pragma once

#include <sol.hpp>
#include <SFML/Graphics.hpp>
#include "TextureBox.h"

namespace Cosmo
{
    namespace Info
    {
        struct SpeedBox
        {
            SpeedBox(int top, int down, int side):
                top{top}, down{down}, side{side}{}
            int top, down, side;

            static void Regist(sol::state &lua)
            {
                lua.new_usertype<SpeedBox>("Speed",
                        sol::constructors<SpeedBox(int top, int down, int side)>());
            }
        };

        struct VectorBox
        {
            VectorBox(float x, float y):
                    vector{ x, y} {}

            const sf::Vector2f vector;

            static void Regist(sol::state &lua)
            {
                lua.new_usertype<VectorBox>("Vector",
                        sol::constructors<VectorBox(float x, float y)>());
            }
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

            static void Regist(sol::state &lua)
            {
                lua.new_usertype<BulletBox>("Bullet",
                                            sol::constructors<BulletBox(const TextureBox& tbox,
                                                                        int trjNum,
                                                                        float speed)>());
            }
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

            static void Regist(sol::state &lua)
            {
                lua.new_usertype<WeaponBox>("Weapon",
                        sol::constructors<WeaponBox(const BulletBox& bbox, float reload, const VectorBox& shift, const VectorBox& dir)>());
            }
        };

        class StarshipBox: public Resource
        {
        public:
            StarshipBox(const TextureBox& tbox,
                        const SpeedBox& sbox,
                        int maxhp,
                        sol::variadic_args va):
                    texture{tbox.texture},
                    maxHP{maxhp},
                    speed{sbox}
            {
                for (auto v : va) {
                    weapons.push_back(v);
                }
            }

            const sf::Texture& texture;
            int maxHP;
            SpeedBox speed;
            std::vector<WeaponBox> weapons;

            static void Regist(sol::state &lua)
            {
                lua["Starship"] = [] (Resource* tbox,
                                     const SpeedBox& sbox,
                                     int maxhp,
                                     sol::variadic_args va) -> Resource*{
                    return new StarshipBox{*dynamic_cast<TextureBox*>(tbox), sbox, maxhp, va};
                };
            }

        };
    }
}