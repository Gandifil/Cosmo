#pragma once
#include "Starship.h"
#include <SFML\Graphics.hpp>
#include <forward_list>
#include <memory>

namespace Cosmo
{
	namespace Entity
	{
		template<typename T>
		class Handler final
		{
		public:
			inline Add(T* entity)
			{
				entities.push_front(std::unique_ptr<T>(entity));
			}

			template <typename U = T>
			inline typename std::enable_if<std::is_base_of<CosmoEntities::Starship, U>::value, void>::type
			Draw(const sf::RenderWindow& wnd)
			{
				for (auto entity : entities)
					wnd.draw(*entity);
			}

			template <typename U = T>
			inline typename std::enable_if<std::is_base_of<CosmoEntities::Starship, U>::value, void>::type
			Update(sf::Time dt)
			{
				for (auto entity : entities)
					entity->Update(dt);
			}
		private:
			std::forward_list<std::unique_ptr<T>> entities;
		};
	}
}