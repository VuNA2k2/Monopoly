#pragma once
#include "GameStateBase.h"
class GameStateMenu : public GameStateBase
{
private:
    sf::Sprite* background;
    std::list<GameButton*> listButton;
public:
    GameStateMenu();

    virtual ~GameStateMenu();

    void exit();

    void pause();

    void resume();

    void init();

    void update(float deltaTime);

    void render(sf::RenderWindow* window);
};



