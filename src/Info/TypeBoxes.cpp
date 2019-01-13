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

CruiserBox::CruiserBox(const TextureBox& tbox,
                       const WeaponBox& leftWeap,
                       const WeaponBox& rightWeap,
                       const SpeedBox& sbox):
    texture{ tbox},
    leftWeapon{leftWeap},
    rightWeapon{rightWeap},
    speed{sbox}
{
};