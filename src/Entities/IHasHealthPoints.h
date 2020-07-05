//
// Created by Gandifil on 27.01.2020.
//

#ifndef COSMO_IHASHEALTHPOINTS_H
#define COSMO_IHASHEALTHPOINTS_H

#include <algorithm>

namespace Cosmo::Entities {
    class IHasHealthPoints {
    public:
        using ValueType = int;
        constexpr static ValueType lowLimit = 0;

        explicit IHasHealthPoints(ValueType maximum) noexcept : maximum{maximum } , value{maximum } {}

        inline ValueType HP() const noexcept {
            return value;
        }

        inline ValueType maxHP() const noexcept {
            return maximum;
        }

        inline void repair(ValueType size) noexcept {
            value = std::min(maximum, value + size);
        }

        inline void damage(ValueType size) noexcept {
            value = std::max(lowLimit, value - size);
        }

    private:
        ValueType value, maximum;
    };
}

#endif //COSMO_IHASHEALTHPOINTS_H
