#pragma once

namespace Cosmo::Entities {
    class IDestroyable {
    public:
        inline bool isDead() { return dead; }

    protected:
        void Die() { dead = true; }

    private:
        bool dead = false;
    };
}