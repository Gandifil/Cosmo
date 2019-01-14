//
// Created by Gandifil on 1/14/2019.
//
#pragma once

namespace Cosmo
{
    namespace Entity
    {
        template<typename T, typename C>
        class Collision final
        {
        public:
            Collision(Handler<T>& checkers, Handler<C>& eventers):
                checkers{checkers}, eventers{eventers}{}

            inline void Check()
            {
                for (auto&& checker : checkers.entities)
                    for (auto&& eventer : eventers.entities)
                        if (checker->isCollised(*eventer))
                            eventer->ColliseEvent(*checker);
            }

        private:
            Handler<T>& checkers;
            Handler<C>& eventers;
        };
    }
}