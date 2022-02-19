#pragma once
#include "GameStateBase.h"
#include "../GameObject/MatrixCells.h"
#include "../GameObject/GameButton.h"
#include "../GameObject/ListPlayers.h"
#include "../GameObject/DiceRoll.h"
#include "../GameObject/Cell.h"
#include "../GameObject/Choice.h"
class GameStateGamePlay : public GameStateBase
{
private:
    Message* goToJail;
    Message* payYourPropertyTaxes;
    sf::Sprite* frame = nullptr;
    sf::Sprite* background2 = nullptr;
    sf::Sprite* background = nullptr;
    GameButton* roll = nullptr;
    std::list<GameButton*> buttons;
    std::vector<sf::Sprite*> frameBackground;
public:
    GameStateGamePlay();

    virtual ~GameStateGamePlay();

    void exit();

    void pause();

    void resume();

    void init();

    void update(float deltaTime);

    void render(sf::RenderWindow* window);
};



