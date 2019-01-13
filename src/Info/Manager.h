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
            Holder<CruiserBox, void> Cruisers;

            inline void Loading()
			{
				sol::state lua;
				lua.open_libraries(sol::lib::base);

				lua.new_usertype<SpeedBox>("SpeedBox",
						sol::constructors<SpeedBox(int top, int down, int side)>());

				lua.new_usertype<TextureBox>("TextureBox", sol::constructors<TextureBox(const std::string& name)>());

				lua.new_usertype<VectorBox>("VectorBox", sol::constructors<VectorBox(float x, float y)>());

				lua.new_usertype<WeaponBox>("WeaponBox",
						sol::constructors<WeaponBox(float reload, const VectorBox& shift, const VectorBox& dir)>());

				lua.new_usertype<CruiserBox>("CruiserBox",
                     sol::constructors<CruiserBox(const TextureBox& tbox,
												  const WeaponBox& leftWeap,
												  const WeaponBox& rightWeap,
												  const SpeedBox& sbox)>());

                lua["addBox"] = [&](const std::string& name, const CruiserBox& box)
                {
                    Cruisers.Add(name, new CruiserBox{box});
                };

                // lua.script("addBox('first', CruiserBox.new('starship1.png'))");
                lua.script_file("entitytypes.lua");
			}

		private:
			Manager(){}
		};
	}
}