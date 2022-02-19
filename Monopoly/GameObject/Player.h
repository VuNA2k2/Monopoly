#pragma once
#include "Animation.h"
#include "../GameManager/ResourceManager.h"
#include "MatrixCells.h"
#include "DiceRoll.h"
#include "GameButton.h"
#include "Shop.h"
enum PSTATE {
	WAIT,
	ROLL,
	RUN,
	BUY,
	SELL,
	CHOSE,
	SNULL,
};

class Player
{
private:
	OWNER owner;
	Animation* ani = nullptr;
	int currentCell;
	int nextCell;
	PSTATE currentState;
	float currentTime;
	int moneyInt;
	sf::Text moneyText;
	sf::Vector2f aimDir, aimDirNorm;
	std::vector<GameButton*> gameButtonBuy;
	bool isDie;
	bool jail;
	bool isPlayMusic;
	bool isComputer;
	int choice;
public:
	Player();
	void init();
	void update(float deltaTime);
	void render(sf::RenderWindow* window);

	void goTo(int cell);
	int getCurrentCell();
	int getNextCell();

	PSTATE getCurrentState();
	void setCurrentState(PSTATE state);
	
	void setMoney(int moneyInt);
	int getMoney();

	OWNER getOwner();
	void setOwner(OWNER owner);

	bool getJail();

	Animation* getAnimation();

	void setComputer(bool isComputer);
};
