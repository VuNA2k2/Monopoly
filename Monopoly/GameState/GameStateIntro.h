#pragma once
#include "GameStateBase.h"
class GameStateIntro : public GameStateBase
{
private:
    sf::Sprite* logo;
    float currentTime;
public:
    GameStateIntro();

    virtual ~GameStateIntro();

    void exit();

    void pause();

    void resume();

    void init();

    void update(float deltaTime);

    void render(sf::RenderWindow* window);
};



