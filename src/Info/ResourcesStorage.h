//
// Created by Gandifil on 29.08.2020.
//

#ifndef COSMO_RESOURCESSTORAGE_H
#define COSMO_RESOURCESSTORAGE_H

#include <map>
#include <string>
#include <memory>
#include <SFML\Graphics.hpp>
#include <sol/sol.hpp>

namespace Cosmo::Info {
    class ResourcesStorage {
    public:
        template<typename T>
        using Holder = std::map<std::string, T>;

        template<typename T>
        static const T& get(const std::string& index) {
            if constexpr (std::is_same_v<T, sf::Texture>) {
                static Holder<std::unique_ptr<T>> holder;

                if (auto it = holder.find(index); it == holder.end()) {
                    auto texture = std::make_unique<sf::Texture>();
                    texture->loadFromFile(index);
                    return *(holder.emplace(index, std::move(texture)).first->second.get());
                }
                else
                    return *(it->second.get());
            }
            else {
                static Holder<T> holder;

                if (auto it = holder.find(index); it == holder.end()) {
                    sol::state lua;
                    lua.open_libraries(sol::lib::base);
                    lua.script_file(index);

                    sol::table declared = lua["this"];
                    return holder.emplace(index, declared).first->second;
                }
                else
                    return it->second;
            }
        }

        inline void clear() noexcept {}

    private:

    };
}


#endif //COSMO_RESOURCESSTORAGE_H
