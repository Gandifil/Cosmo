#pragma once
#include <SFML\System.hpp>
#include <functional>

namespace Cosmo
{
	namespace Bullet 
	{
		class Trajectory final
		{
		public:
			Trajectory(std::function<sf::Vector2f(float)> f): f{f}, t{0}
			{}

			sf::Vector2f Update(sf::Time dt)
			{
				return f(t += dt.asSeconds());
			}
		private:
			float t;
			std::function<sf::Vector2f(float)> f;
		};
	}
}