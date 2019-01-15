#pragma once
#include <SFML\System.hpp>
#include <functional>
#include <math.h>

namespace Cosmo
{
	namespace Utils
	{
        static sf::Vector2f linear10(const sf::Vector2f& dir, float speed, float t)
        {
            return (t * speed) * dir;
        }

        static float getAngle_linear10(const sf::Vector2f& dir, float speed, float t)
        {
            sf::Vector2f a{0, -1.f};
            const float radToDegrees = (360.f / (2.f * (float)M_PI));
            float b = a.x*dir.x + a.y*dir.y;
            return acosf(b) * ((dir.x > 0)?radToDegrees:-radToDegrees);
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

			float GetAngle()
            {
			    return getAngle_linear10(dir, speed, t);
            }

		private:
			float t;
            TrajectoryDelegate f;
			sf::Vector2f dir, begin;
			float speed;
		};
	}
}