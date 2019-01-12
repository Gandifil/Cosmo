#pragma once
#include <SFML/Graphics.hpp>

namespace Cosmo
{
	namespace UI {
		class Scene
		{
			public:
				virtual int HandleEvent(sf::Event event) = 0;
				virtual void Update(sf::Time dt) = 0;
				virtual void Render() = 0;

				Scene(Scene const&) = delete;
				Scene& operator= (Scene const&) = delete;

				inline static Scene*& Instance()
				{
					return instance;
				}

				static void Add(Scene* scene)
				{
					scene->stack = instance;
					instance = scene;
				}
			protected:
				Scene(){}

				void Turn(Scene* scene)
				{
					scene->stack = instance->stack;
					delete instance;
					instance = scene;
				}

				void Remove()
				{
					auto stack = instance->stack;
					delete instance;
					instance = stack;
				}
			private:
				static Scene* instance;
				Scene* stack = nullptr;
		};
	}
}