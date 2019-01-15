#pragma once
#include <SFML\System.hpp>
#include <functional>

namespace Cosmo
{
	namespace Utils
	{
        static sf::Vector2f linear10(const sf::Vector2f& delta, float t)
        {
            return (t * 10.f) * delta;
        }

		class Trajectory final
		{
		public:

			Trajectory(const sf::Vector2f& start, const sf::Vector2f& delta,
			        std::function<sf::Vector2f(const sf::Vector2f&, float)> f):
			    t{0}, delta{delta}, begin{start}, f{f}
			{}

			sf::Vector2f UpdatePosition(sf::Time dt)
			{
				return begin + f(delta, t += dt.asSeconds());
			}

		private:
			float t;
            std::function<sf::Vector2f(const sf::Vector2f&, float)> f;
			sf::Vector2f delta, begin;
		};
	}
}