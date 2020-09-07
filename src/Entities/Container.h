//
// Created by Gandifil on 26.01.2020.
//

#ifndef COSMO_CONTAINER_H
#define COSMO_CONTAINER_H

#include <vector>
#include <string>
#include <iostream>
#include "IEntity.h"
#include "BlockAllocator.h"
#include "Bullet.h"
#include "../Control/IControllable.h"

namespace Cosmo::Entities {

    class Container: public sf::Drawable, public IUpdatable {
    public:
        template<typename T>
        using ParametersType = typename T::Parameters;

        template<typename T, typename... Args>
        inline T* add(const std::string& index, Args&&... args) {
            try {
                auto parameters = Info::ResourcesStorage::get<ParametersType<T>>(index);
                return add<T, Args... >(parameters, std::forward<Args>(args)... );
            }
            catch (const std::exception& str) {
                std::cerr << str.what() << std::endl;
            }
        }

        template<typename T, typename... Args>
        inline T* add(const ParametersType<T>& parameters, Args&&... args) {
            auto pointer = new (allocator.allocate(sizeof(T))) T{parameters, std::forward<Args>(args)... };
            entities.push_front(pointer);
            if constexpr (std::is_base_of_v<Control::IControllable, T>)
                players.push_back(pointer);
            return pointer;
        }
//
//        template<typename T, typename... Args>
//        inline T* addPlayer(const std::string& index, Args&&... args) {
//            auto parameters = Info::ResourcesStorage::get<T::Parameters>(index);
//            T* pointer = new (allocator.allocate(sizeof(T))) T{parameters,  std::forward<Args>(args)... };
//            entities.push_front(pointer);
//            return pointer;
//        }

        inline void draw(sf::RenderTarget &target, sf::RenderStates states) const override {
            for(auto entity: entities)
                target.draw(*entity, states);
        }

        inline void update(sf::Time dt) override {
            for(auto entity: entities)
                entity->update(dt);
        }

        inline void checkCollision()  {
            for(auto entity: entities) {
                auto starship = dynamic_cast<Starship*>(entity);
                if (starship)
                    for(auto entity: entities) {
                        auto bullet = dynamic_cast<Bullet*>(entity);
                        if (bullet)
                            if (starship->team() != bullet->team() && starship->isColliseWith(bullet)) {
                                bullet->colliseWith(starship);
                                starship->colliseWith(bullet);
                            }
                    }
            }
        }

        inline void destroyDead() {
            entities.remove_if([&](auto entity) {
                if (entity->isDead()) {
                    allocator.deallocate(entity);
                    return true;
                }
                return false;
            });
        }

        inline void clear() noexcept {
            players.clear();
            entities.clear();
            allocator.deallocateAll();
        }

        static Container& instance() {
            static Container container;
            return container;
        }

        std::vector<Starship*> players;
    private:
        BlockAllocator<IEntity, 250, 1024> allocator;
        std::forward_list<IEntity *> entities;

        template<typename T, typename... Args>
        inline T* _add(Args&&... args) {
            auto pointer = new (allocator.allocate(sizeof(T))) T{std::forward<Args>(args)... };
            entities.push_front(pointer);
            if constexpr (std::is_base_of_v<Control::IControllable, T>)
                players.push_back(pointer);
            return pointer;
        }
    };
}

#endif //COSMO_CONTAINER_H
