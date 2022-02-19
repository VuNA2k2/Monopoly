#pragma once
#include "../GameManager/Singleton.h"
#include <list>
#include "SFML/Graphics.hpp"


class GameStateBase;
enum STATE {
    INVALID = 0,
    INTRO,
    MENU,
    PICKMODE,
    GAMEPLAY,
    ENDGAME,
};
class GameStateMachine : public Singleton<GameStateMachine> {
private:
    std::list<GameStateBase*> stateStack;
    GameStateBase* currentState;
    GameStateBase* nextState;

public:
    GameStateMachine();
    ~GameStateMachine();

    void changeState(GameStateBase* state);
    void changeState(STATE state);
    void pushState(STATE state);
    void popState();

    void performStateChange();

    GameStateBase* getCurrentState() const;
    GameStateBase* getNextState() const;
    bool needToChangeState();
    bool hasState();
};