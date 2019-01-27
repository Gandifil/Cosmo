//
// Created by Gandifil on 1/13/2019.
//
#include "TypeBoxes.h"
#include "Manager.h"

using namespace Cosmo::Info;

TextureBox::TextureBox(const std::string& name):
    texture{Manager::Instance().Textures[name]}
{
};

StarshipBox::StarshipBox(const TextureBox& tbox,
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