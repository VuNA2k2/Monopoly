#include "ListPlayers.h"
#include "../GameState/GameStateMachine.h"
ListPlayers::ListPlayers()
{
}

void ListPlayers::init()
{
	Player* player = nullptr;
	player = new Player();
	player->init();
	player->setOwner(RED);
	players.push_back(player);

	player = new Player();
	player->init();
	player->setOwner(YELLOW);
	players.push_back(player);

	player = new Player();
	player->init();
	player->setOwner(CYAN);
	players.push_back(player);

	player = new Player();
	player->init();
	player->setOwner(BLUE);
	players.push_back(player);
	currentPlayer = 0;
	round = 30;
	text = new sf::Text();
	text->setFont(*DATA->getFont("font"));
	text->setFillColor(sf::Color::Yellow);
	text->setOutlineThickness(4);
	text->setOutlineColor(sf::Color::Black);
	text->setCharacterSize(72);
	text->setString(std::to_string(round));
	text->setOrigin(text->getGlobalBounds().width / 2, text->getGlobalBounds().height / 2);
	text->setPosition(screenWidth / 2, 100);

	for (int i = players.size() - numComputer; i < players.size(); i++) players[i]->setComputer(true);
}

void ListPlayers::update(float deltaTime)
{
	if (players[currentPlayer]->getJail()) currentPlayer++;
	players[currentPlayer]->update(deltaTime);
	if (players[currentPlayer]->getCurrentState() == SNULL) {
		players[currentPlayer]->setCurrentState(WAIT);
		currentPlayer++;
	}
	if (currentPlayer == players.size()) {
		round--;
		text->setString(std::to_string(round));
		text->setOrigin(text->getGlobalBounds().width / 2, text->getGlobalBounds().height / 2);
		text->setPosition(screenWidth / 2, 100);
		currentPlayer = 0;
	}
	checkEndGame();
}

void ListPlayers::render(sf::RenderWindow* window)
{
	for (auto it : players) {
		it->render(window);
	}
	window->draw(*text);
}

std::vector<Player*> ListPlayers::getListPlayers()
{
	return players;
}

PSTATE ListPlayers::getState()
{
	return players[currentPlayer]->getCurrentState();
}

int ListPlayers::getCurrentCell()
{
	return players[currentPlayer]->getCurrentCell();
}

void ListPlayers::setMoneyForOwner(OWNER owner, int money)
{
	for (auto it : players) {
		if (it->getOwner() == owner) {
			it->setMoney(money);
		}
	}
}

int ListPlayers::getMoneyForOwner(OWNER owner)
{
	for (auto it : players) {
		if (it->getOwner() == owner) {
			return it->getMoney();
		}
	}
}

int ListPlayers::getCurrentPlayer()
{
	return currentPlayer;
}

Player* ListPlayers::getWinner()
{
	int max = 0;
	Player* tmp = new Player();
	for (auto it : players) {
		if (it->getMoney() > max) {
			max = it->getMoney();
			tmp = it;
		}
	}
	return tmp;
}

void ListPlayers::setComputer(int numComputer)
{
	this->numComputer = numComputer;
}

void ListPlayers::checkEndGame()
{
	int d = 0;
	if (round == 0) {
		GameStateMachine::getInstance()->pushState(ENDGAME);
		DATA->getMusic("background")->stop();
		DATA->getMusic("endgame")->play();
	}
	for (auto it : players) {
		if (it->getMoney() < 0) {
			d++;
		}
	}
	if (d == 3) {
		GameStateMachine::getInstance()->pushState(ENDGAME);
		DATA->getMusic("background")->stop();
		DATA->getMusic("endgame")->play();
	}
}
