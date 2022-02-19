#include "Application.h"
#include "GameState/GameStateBase.h"

void Application::init() {
    window = new sf::RenderWindow(sf::VideoMode(screenWidth, screenHeight), title, sf::Style::Fullscreen);
    window->setFramerateLimit(200);
    window->setVerticalSyncEnabled(false);
    GameStateMachine::getInstance()->pushState(INTRO);
    WindowConnector::getInstance()->setWindow(window);
}

void Application::update() {
    if (GameStateMachine::getInstance()->needToChangeState()) {
        GameStateMachine::getInstance()->performStateChange();
    }
    GameStateMachine::getInstance()->getCurrentState()->update(deltaTime);
}

void Application::render() {
    window->clear();
    GameStateMachine::getInstance()->getCurrentState()->render(window);
    window->display();
}

void Application::run() {
    init();
    sf::Clock clock;
    while (window->isOpen()) {
        deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window->pollEvent(event)) {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                window->close();
            }
        }
        update();
        render();
    }
}

Application::~Application() {
    if (window != nullptr) delete window;
    GameStateMachine::removeInstance();
    ResourceManager::removeInstance();
    delete this;
}
