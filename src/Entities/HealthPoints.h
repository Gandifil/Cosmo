//
// Created by Gandifil on 27.01.2020.
//

#ifndef COSMO_HEALTHPOINTS_H
#define COSMO_HEALTHPOINTS_H

#include <algorithm>

namespace Cosmo::Entities {
    class HealthPoints {
    public:
        using ValueType = int;

        HealthPoints(ValueType maximum) : maximum{ maximum } , value{ maximum } {}

        inline ValueType getValue() const {
            return value;
        }

        inline ValueType getMax() const {
            return maximum;
        }

    protected:
        inline void repair(ValueType size) {
            value = std::max(maximum, value + size);
        }

        inline void damage(ValueType size) {
            value = std::min(0, value - size);
        }

    private:
        ValueType value, maximum;
    };
}

#endif //COSMO_HEALTHPOINTS_H
