#pragma once
#include "Player.h"
#define LP ListPlayers::getInstance()
class ListPlayers : public Singleton<ListPlayers> {
private:
	std::vector<Player*> players;
	int currentPlayer;
	int round;
	sf::Text* text;
	void checkEndGame();
	int numComputer;
public:
	ListPlayers();
	void init();
	void update(float deltaTime);
	void render(sf::RenderWindow* window);

	std::vector<Player*> getListPlayers();

	PSTATE getState();
	int getCurrentCell();

	void setMoneyForOwner(OWNER owner, int money);
	int getMoneyForOwner(OWNER owner);

	int getCurrentPlayer();

	Player* getWinner();
	void setComputer(int numComputer);
};