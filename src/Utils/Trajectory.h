#pragma once
#include <SFML\System.hpp>
#include <functional>

namespace Cosmo
{
	namespace Utils
	{
        static sf::Vector2f linear10(const sf::Vector2f& dir, float speed, float t)
        {
            return (t * speed) * dir;
        }

		class Trajectory final
		{
		public:
		    typedef std::function<sf::Vector2f(const sf::Vector2f&, float, float)> TrajectoryDelegate;

			Trajectory(const sf::Vector2f& start, const sf::Vector2f& dir,
                       TrajectoryDelegate f, float speed):
			    t{0}, dir{dir}, begin{start}, f{f}, speed{speed}
			{}

			sf::Vector2f UpdatePosition(sf::Time dt)
			{
				return begin + f(dir, speed, t += dt.asSeconds());
			}

		private:
			float t;
            TrajectoryDelegate f;
			sf::Vector2f dir, begin;
			float speed;
		};
	}
}