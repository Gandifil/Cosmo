//
// Created by Gandifil on 23.01.2020.
//

#ifndef COSMO_APPLICATION_H
#define COSMO_APPLICATION_H

#include "UI/Window.h"
#include "UI/MainMenu.h"
#include "IUpdatable.h"

namespace Cosmo {
    class Application final: public IUpdatable {
    public:
        Application();

        int exec();

    private:
        Cosmo::UI::Window window;
        sf::Clock clock;
        bool isAlive = true;

        inline void update(sf::Time dt) override;
        inline void handleEvents();
        inline bool isRunning();
    };

    using namespace Cosmo::UI;

    Application::Application():
            window{ Cosmo::Info::Config::Instance() }
    {
        Scene::stack().push(new MainMenu{ window.getRenderWindow() });
    };

    int Application::exec(){
        while(isRunning())
        {
            handleEvents();
            update(clock.restart());
            window.Render();
        }
        return EXIT_SUCCESS;
    }

    inline void Application::update(sf::Time dt) {
        window.update(dt);
        Scene::current()->update(dt);
    }

    inline void Application::handleEvents(){
        sf::Event event;
        while (window.getRenderWindow().pollEvent(event))
            if (Scene::current()->HandleEvent(event) == 0)
                isAlive = false;
    }

    inline bool Application::isRunning(){
        return isAlive;
    }
}

#endif //COSMO_APPLICATION_H
