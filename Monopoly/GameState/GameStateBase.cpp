#include "GameStateBase.h"
#include "GameStateIntro.h"
#include "GameStateMenu.h"
#include "GameStateGamePlay.h"
#include "GameStateEndGame.h"
#include "GameStatePickMode.h"
GameStateBase* GameStateBase::createState(STATE state)
{
	GameStateBase* gameStateBase = nullptr;
	switch (state) {
	case INTRO:
		gameStateBase = new GameStateIntro();
		break;
	case MENU:
		gameStateBase = new GameStateMenu();
		break;
	case PICKMODE:
		gameStateBase = new GameStatePickMode();
		break;
	case GAMEPLAY:
		gameStateBase = new GameStateGamePlay();
		break;
	case ENDGAME:
		gameStateBase = new GameStateEndGame();
		break;
	default:
		break;
	}
	return gameStateBase;
}
