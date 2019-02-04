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

                //lua.new_usertype<Resource>("Resource");
                //sol::resolve<Sprite*()>(&Sprite::create)
                lua.set_function("Texture", [](const std::string& name)-> Resource* {
                    TextureBox *instance = new TextureBox{};
                    instance->texture.loadFromFile(name);
                    return instance;
                });
                //lua.script("texture = Texture('cruiser01.png')");
                //lua["Texture1"] = create2;
            }
        private:
            static Resource* create1(const std::string& name){
                TextureBox *instance = new TextureBox{};
                instance->texture.loadFromFile(name);
                return instance;
            }


            static Resource* create2(const std::string& name,
                    int left, int top, int right, int bottom){
                TextureBox *instance = new TextureBox{};
                instance->texture.loadFromFile(name, sf::IntRect());
                return instance;
            }
        };
    }
}
#endif //COSMO_TEXTURE_H
