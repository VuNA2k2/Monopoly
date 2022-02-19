#pragma once
#include "GameStateBase.h"
#include "../GameObject/GameButton.h"
#include "../GameObject/Animation.h"
class GameStateEndGame : public GameStateBase
{
private:
    sf::Sprite* background;
    std::vector<GameButton*> listButtons;
    Animation* ani;
public:
    GameStateEndGame();

    virtual ~GameStateEndGame();

    void exit();

    void pause();

    void resume();

    void init();

    void update(float deltaTime);

    void render(sf::RenderWindow* window);
};



