#pragma once
#include <SFML\Graphics.hpp>
#include <sol.hpp>
#include "Holder.h"
#include "ReadTexture.h"
#include "TypeBoxes.h"

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

			Holder<sf::Texture, ReadTexture> Textures;
            Holder<StarshipBox, void> Starships;

            inline void Loading()
			{
				sol::state lua;
				lua.open_libraries(sol::lib::base);

				lua.new_usertype<SpeedBox>("SpeedBox",
						sol::constructors<SpeedBox(int top, int down, int side)>());

				lua.new_usertype<TextureBox>("TextureBox", sol::constructors<TextureBox(const std::string& name)>());

				lua.new_usertype<VectorBox>("VectorBox", sol::constructors<VectorBox(float x, float y)>());

				lua.new_usertype<WeaponBox>("WeaponBox",
					sol::constructors<WeaponBox(const BulletBox& bbox, float reload, const VectorBox& shift, const VectorBox& dir)>());

				lua.new_usertype<BulletBox>("BulletBox",
					sol::constructors<BulletBox(const TextureBox& tbox,
												int trjNum,
												float speed)>());

				lua.new_usertype<StarshipBox>("StarshipBox",
											 sol::constructors<StarshipBox(const TextureBox& tbox,
																		  const SpeedBox& sbox,
																		  int maxhp,
																		  sol::variadic_args va)>());

                lua["addBox"] = [&](const std::string& name, const StarshipBox& box)
                {
					Starships.Add(name, new StarshipBox{box});
                };

                lua.script_file("entitytypes.lua");
			}

		private:
			Manager(){}
		};
	}
}