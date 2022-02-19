#pragma once
#include "GameState/GameStateMachine.h"
class Application
{
private:
    sf::RenderWindow* window;
    float deltaTime;
    void init();
    void update();
    void render();
public:
    void run();

    virtual ~Application();
};

