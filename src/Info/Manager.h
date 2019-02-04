#pragma once
#include "Resource.h"
#include "TextureBox.h"

namespace Cosmo
{
	namespace Info
	{

		class Manager final
		{
		public:
			static Manager& Instance()
			{
				static Manager manager;
				return manager;
			}

			template<typename T>
			inline const T& Get(const std::string& index)
			{
				auto found = resources.find(index);

				if (found == resources.end())
					throw new int{0};
				else
				{
					Resource *src = found->second.get();
					T *res = dynamic_cast<T*>(src);
					return *res;

				}
			}

		private:
			Manager()
			{
            	Loading();
            }

			std::map<std::string, std::unique_ptr<Resource>> resources;

            inline void Loading(){
				sol::state lua;

				lua.open_libraries();
				//lua.new_usertype<Resource>("Resource");
				SolRegist<WeaponBox, SpeedBox, BulletBox, VectorBox>(lua);
				SolRegist<TextureBox, StarshipBox>(lua);

                lua["add"] = [&] (const std::string& name, Resource* resource) {
                    Add(name, resource);
                };

                //lua.script("texture = Texture('cruiser01.png')");
                lua.script_file("entitytypes.lua");
            }

            inline void Add(const std::string& name, Resource* resource)
            {
                resources.insert(std::make_pair(name, std::unique_ptr<Resource>(resource)));
            }
		};
	}
}