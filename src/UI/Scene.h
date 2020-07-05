//
// Created by Gandifil on 24.01.2020.
//

#ifndef COSMO_UI_SCENE
#define COSMO_UI_SCENE

#include <stack>
#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/Drawable.hpp>
#include "../IUpdatable.h"
#include "../IEventHandler.h"

namespace Cosmo::UI {
    class Scene: public sf::Drawable, public sf::NonCopyable, public IUpdatable, public IEventHandler {
    private:
        inline static auto& stack() noexcept {
            static std::stack<Scene*> stack;
            return stack;
        }

	public:
		inline static Scene* current() noexcept {
			return stack().top();
		}

        inline static void toNext(Scene* scene) noexcept {
            stack().push(scene);
        }

        inline static void change(Scene* scene) noexcept {
            backToLast();
            toNext(scene);
        }

	protected:
	    inline static void backToLast() noexcept {
		    stack().pop();
		}
	};
}

#endif