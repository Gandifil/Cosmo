//
// Created by Gandifil on 2/4/2019.
//

#ifndef COSMO_SHADERBOX_H
#define COSMO_SHADERBOX_H

#include <fstream>
#include <SFML/Graphics/Shader.hpp>
#include "Resource.h"

namespace Cosmo
{
    namespace Info
    {
        class ShaderBox: public Resource
        {
        public:
            ShaderBox(const std::string& name)
            {
                std::ifstream file(prefix + name);
                shaderText = {(std::istreambuf_iterator<char>(file)),
                                std::istreambuf_iterator<char>()};
            }

            static void Regist(sol::state &lua){
                lua.set_function("Shader",
                        [&](const std::string& name)-> Resource* {
                            return new ShaderBox{name};
                        }
                );
            }

            inline const std::string& getText() const
            {
                return shaderText;
            }
        private:
            static constexpr const char* prefix = "shaders/";

            std::string shaderText;
        };
    }
}
#endif //COSMO_SHADERBOX_H
