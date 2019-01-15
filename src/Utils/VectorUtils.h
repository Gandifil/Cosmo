//
// Created by Gandifil on 1/15/2019.
//
#ifndef VECTOR_UTILS
#define VECTOR_UTILS
#include <math.h>
#include <TGUI/Vector2f.hpp>

namespace Cosmo
{
    namespace Utils
    {
        static inline float VecLength(const sf::Vector2f& vec)
        {
            return sqrt(vec.x * vec.x + vec.y * vec.y);
        }

        static sf::Vector2f Normalize(const sf::Vector2f& vec)
        {
            return vec / VecLength(vec);
        }
    }
}
#endif