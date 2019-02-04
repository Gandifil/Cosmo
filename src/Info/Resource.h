//
// Created by Gandifil on 2/2/2019.
//

#ifndef COSMO_RESOURCE_H
#define COSMO_RESOURCE_H

#include <sol.hpp>

namespace Cosmo
{
    namespace Info
    {
        class Resource
        {
        public:
                virtual ~Resource() = default;
        };

        template<typename... NONE>
        typename std::enable_if<(sizeof...(NONE) == 0), void>::type
        SolRegist(sol::state& lua)
        {
            //HEAD::Regist(lua);
        }

        template<typename HEAD, typename... TAIL>
        void SolRegist(sol::state& lua)
        {
            HEAD::Regist(lua);
            SolRegist<TAIL...>(lua);
        }
    }
}
#endif //COSMO_RESOURCE_H
