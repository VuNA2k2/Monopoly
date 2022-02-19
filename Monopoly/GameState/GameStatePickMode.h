#pragma once
#include"GameStateBase.h"

class GameStatePickMode : public GameStateBase
{
private:
    sf::Sprite* background;
    std::list<GameButton*> listButton;
public:
    GameStatePickMode();

    virtual ~GameStatePickMode();

    void exit();

    void pause();

    void resume();

    void init();

    void update(float deltaTime);

    void render(sf::RenderWindow* window);
};