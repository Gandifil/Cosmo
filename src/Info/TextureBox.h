//
// Created by Gandifil on 2/1/2019.
//

#ifndef COSMO_TEXTURE_H
#define COSMO_TEXTURE_H

#include "Resource.h"

namespace Cosmo
{
    namespace Info
    {
        class TextureBox: public Resource
        {
        public:
            sf::Texture texture;

            static void Regist(sol::state &lua){

                lua.set_function("Texture", sol::overload(
                    [&](const std::string& name)-> Resource* {
                        TextureBox *instance = new TextureBox{};
                        instance->texture.loadFromFile(prefix + name);
                        return instance;
                    },
                    [&](const std::string& name, int left, int top, int right, int bottom) -> Resource*{
                        TextureBox *instance = new TextureBox{};
                        instance->texture.loadFromFile(prefix + name, sf::IntRect(left, top, right ,bottom));
                        return instance;
                    }
                ));
            }
        private:
            static constexpr const char* prefix = "images/";
        };
    }
}
#endif //COSMO_TEXTURE_H
