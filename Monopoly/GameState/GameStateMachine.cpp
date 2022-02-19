#include "GameStateMachine.h"
#include "GameStateBase.h"



GameStateMachine::GameStateMachine() {
    currentState = nullptr;
    nextState = nullptr;
}

GameStateMachine::~GameStateMachine() {
    if (currentState != nullptr) delete currentState;
    if (nextState != nullptr) delete nextState;
    for (auto it : stateStack) {
        if (it != nullptr) delete it;
    }
    stateStack.clear();
}

GameStateBase* GameStateMachine::getCurrentState() const {
    return currentState;
}

GameStateBase* GameStateMachine::getNextState() const {
    return nextState;
}

void GameStateMachine::changeState(GameStateBase* state) {
    nextState = state;
}

void GameStateMachine::changeState(STATE state) {
    GameStateBase* gameState = GameStateBase::createState(state);
    changeState(gameState);
}

void GameStateMachine::pushState(STATE state) {
    GameStateBase* gameStateBase = GameStateBase::createState(state);
    if (!stateStack.empty()) {
        stateStack.back()->pause();
    }
    nextState = gameStateBase;
}

void GameStateMachine::popState() {
    if (!stateStack.empty()) {
        stateStack.back()->exit();
        stateStack.pop_back();
    }
    if (!stateStack.empty()) {
        stateStack.back()->resume();
    }
    currentState = stateStack.back();
}


void GameStateMachine::performStateChange() {
    if (nextState != nullptr) {
        if (!stateStack.empty()) {
            stateStack.back()->exit();
        }
        stateStack.push_back(nextState);
        stateStack.back()->init();
        currentState = nextState;
    }
    nextState = nullptr;
}

bool GameStateMachine::needToChangeState() {
    return nextState != nullptr;
}

bool GameStateMachine::hasState() {
    return stateStack.empty();
}
