//
// Created by Gandifil on 23.01.2020.
//

#ifndef COSMO_APPLICATION_H
#define COSMO_APPLICATION_H

#include "UI/Window.h"
#include "UI/MainMenu.h"
#include "IUpdatable.h"

namespace Cosmo {
    class Application final: public IUpdatable, public sf::NonCopyable {
    public:
        Application();

        int run();

    private:
        Cosmo::UI::Window window;
        bool isAlive = true;

        inline void update(sf::Time dt) override;
        inline void handleEvents();
        inline bool isRunning();
    };

    using namespace Cosmo::UI;

    Application::Application(): window{ Cosmo::Info::Config::Instance() } {
        Scene::toNext(new MainMenu{ window.getRenderWindow() });
    };

    int Application::run(){
        while(isRunning())
        {
            handleEvents();
            static sf::Clock clock;
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
            Scene::current()->handleEvent(event);
    }

    inline bool Application::isRunning(){
        return isAlive;
    }
}

#endif //COSMO_APPLICATION_H
