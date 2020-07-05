//
// Created by Gandifil on 04.07.2020.
//

#ifndef COSMO_ICOLLISIONABLE_H
#define COSMO_ICOLLISIONABLE_H

namespace Cosmo::Entities {
    class IEntity;

    class ICollisionable {
    public:
        inline virtual bool isColliseWith(const IEntity *entity) const noexcept { return false; };

        inline virtual void colliseWith(const IEntity *entity) noexcept {};
    };
}

#endif //COSMO_ICOLLISIONABLE_H
