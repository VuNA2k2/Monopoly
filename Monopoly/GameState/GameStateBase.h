#pragma once
#include "../GameManager/ResourceManager.h"
#include "GameStateMachine.h"
#include <list>

class GameStateBase {
public:
    GameStateBase() {};

    virtual ~GameStateBase() {};

    virtual void exit() = 0;

    virtual void pause() = 0;

    virtual void resume() = 0;

    virtual void init() = 0;

    virtual void update(float deltaTime) = 0;

    virtual void render(sf::RenderWindow* window) = 0;

    static GameStateBase* createState(STATE state);
};