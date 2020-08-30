//
// Created by Gandifil on 1/15/2019.
//
#ifndef VECTOR_UTILS
#define VECTOR_UTILS

#include <math.h>
#include <TGUI/Vector2f.hpp>

namespace Cosmo::Utils {
    template<typename T>
    inline T toRadians(T degrees) noexcept {
        constexpr T D_TO_R = M_PI / 180.;
        return degrees * D_TO_R;
    }

    template<typename T>
    class  ExtendedVector: public sf::Vector2<T> {
    public:
        ExtendedVector() = default;

        ExtendedVector(T X, T Y): sf::Vector2<T>{X, Y}{}

        ExtendedVector(const sf::Vector2<T>& vec): sf::Vector2<T>{vec.x, vec.y}{}

        inline float length() const noexcept {
            return sqrt(sf::Vector2<T>::x * sf::Vector2<T>::x +
                                sf::Vector2<T>::y * sf::Vector2<T>::y);
        }

        inline ExtendedVector<T> normalized() const noexcept {
            return *this / length();
        }

        inline static ExtendedVector<T> fromRadians(T radians) noexcept {
            return ExtendedVector<T>{ cos(radians), sin(radians) };
        }

        inline static ExtendedVector<T> fromDegrees(T degrees) noexcept {
            return fromRadians(toRadians(degrees));
        }
    };
}
#endif