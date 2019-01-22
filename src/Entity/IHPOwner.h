//
// Created by Gandifil on 1/20/2019.
//
#ifndef COSMO_IHPOWNER_H
#define COSMO_IHPOWNER_H

#include "IDestroyable.h"

namespace Cosmo
{
    namespace Entity
    {
        class IHPOwner: public IDestroyable
        {
        public:
            IHPOwner(int amaxHP): hp{amaxHP}, maxHP{amaxHP}{}

            inline int getHP() const { return hp; }

            inline int getMaxHP() const { return maxHP; }

            inline void Damage(unsigned int value) {
                hp -= value;
                if (hp <= 0) Die();
            }

            inline void Repair(unsigned int value) {
                hp += value;
                if (maxHP < hp) hp = maxHP;
            }

        private:
            int hp, maxHP;
        };
    }
}
#endif //COSMO_IHPOWNER_H
