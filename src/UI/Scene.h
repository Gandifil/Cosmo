//
// Created by Gandifil on 24.01.2020.
//

#ifndef COSMO_UI_SCENE
#define COSMO_UI_SCENE

#include <SFML/Graphics.hpp>
#include <stack>
#include "../IUpdatable.h"
#include "../IEventHandler.h"

namespace Cosmo::UI {
	class Scene: public sf::NonCopyable, public IUpdatable, public IEventHandler {
	public:
		virtual void Render() = 0;

		inline static auto& stack()
		{
			static std::stack<Scene*> stack;
			return stack;
		}

		inline static Scene* current(){
			return stack().top();
		}
	};
}

#endif