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

CruiserBox::CruiserBox(const StarshipBox& ssbox,
                       const WeaponBox& leftWeap,
                       const WeaponBox& rightWeap):
    leftWeapon{leftWeap},
    rightWeapon{rightWeap},
    starshipBox{ssbox}
{
};