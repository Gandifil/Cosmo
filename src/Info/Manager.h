#pragma once
#include "Holder.h"
#include "ReadTexture.h"
#include <SFML\Graphics.hpp>

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
		private:
			Manager(){}
		};
	}
}