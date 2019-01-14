#pragma once
#include "Starship.h"
#include "IDestroyable.h"
#include "IUpdateable.h"
#include <SFML\Graphics.hpp>
#include <forward_list>
#include <memory>

namespace Cosmo
{
	namespace Entity
	{
		template<typename T>
		class Handler
		{
		public:
			inline void Add(T* entity)
			{
				entities.push_front(std::move(std::unique_ptr<T>(entity)));
			}

			template <typename U = T>
			inline typename std::enable_if<std::is_base_of<Cosmo::Entity::ISpriteOwner, U>::value, void>::type
			Draw(sf::RenderWindow& wnd, sf::RenderStates states) const
			{
				for (auto&& entity : entities)
					wnd.draw(*entity);
			}

			template <typename U = T>
			inline typename std::enable_if<std::is_base_of<Cosmo::Entity::IUpdateable, U>::value, void>::type
			Update(sf::Time dt)
			{
				for (auto&& entity : entities)
					entity->Update(dt);
			}

            template <typename U = T>
            inline typename std::enable_if<std::is_base_of<Cosmo::Entity::IDestroyable, U>::value, void>::type
            RemoveDeads()
            {
				entities.remove_if([](std::unique_ptr<T>& entity) { return entity->isDead();});
//			    auto it = entities.begin();
//			    while (it != entities.end())
//                    if ((*it)->isDead())
//                        entities.remove(it);
//                    else
//                        ++it;

            }

			std::forward_list<std::unique_ptr<T>> entities;
		};
	}
}