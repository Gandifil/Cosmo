//
// Created by Gandifil on 26.01.2020.
//

#ifndef COSMO_CONTAINER_H
#define COSMO_CONTAINER_H

#include <vector>
#include "IEntity.h"
#include "BlockAllocator.h"
#include "Bullet.h"

namespace Cosmo::Entities {

    class Container: public sf::Drawable, public IUpdatable {
    public:
        template<typename T, typename... Args>
        inline T* add(Args&&... args) {
            auto pointer = new (allocator.allocate(sizeof(T))) T{ std::forward<Args>(args)... };
            entities.push_front(pointer);
            return pointer;
        }

        template<typename T, typename... Args>
        inline T* addPlayer(Args&&... args) {
            T* pointer = new (allocator.allocate(sizeof(T))) T{ std::forward<Args>(args)... };
            entities.push_front(pointer);
            players.push_back(pointer);
            return pointer;
        }

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

        static Container& instance() {
            static Container container;
            return container;
        }

        std::vector<Starship*> players;
    private:
        BlockAllocator<IEntity, 250, 1024> allocator;
        std::forward_list<IEntity *> entities;
    };
}

#endif //COSMO_CONTAINER_H
