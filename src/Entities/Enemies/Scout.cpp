//
// Created by Gandifil on 30.08.2020.
//

#include "Scout.h"

using namespace Cosmo::Entities::Enemies;

Scout::Parameters::Parameters(const sol::table& lua):
        Entities::Starship::Parameters{ lua },
        weapon{ lua["weapon"].get<sol::table>() }{}

Scout::Scout(const Scout::Parameters& parameters, const sf::Vector2f& pos):
        Starship{parameters, pos}, weapon{parameters.weapon, *this}
{
    Info::Config& conf = Info::Config::Instance();
    int w = conf.getParam(Info::Config::WWindow);
    int h = conf.getParam(Info::Config::HWindow);

    dstPoint = {float(std::rand() % w), float(std::rand() % h)};
    sprite.setRotation(180.f);
}

void Scout::update(sf::Time dt) {
    auto pos = sprite.getPosition();
    sf::Vector2f delta = dstPoint - pos;
    float sc = dt.asSeconds();
    float top = parameters.up * sc;
    float down = parameters.down * sc;
    float side = parameters.side * sc;
    if (abs(delta.x) > side)
    delta.x = (delta.x > 0)? side : -side;

    if (delta.y > 0) {
        if (abs(delta.y) > top)
        delta.y = top;
    }
    else
        if (abs(delta.y) > down)
    delta.y = -down;

    sprite.move(delta);

    weapon.fireAlways(dt);
}