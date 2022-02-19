#include "GameStateEndGame.h"
#include "../GameObject/ListPlayers.h"
GameStateEndGame::GameStateEndGame()
{
}

GameStateEndGame::~GameStateEndGame()
{
	if (background != nullptr) delete background;
	for (auto it : listButtons) {
		if (it != nullptr) {
			delete it;
		}
	}
	listButtons.clear();
	if (ani != nullptr) delete ani;
}

void GameStateEndGame::exit()
{
}

void GameStateEndGame::pause()
{
}

void GameStateEndGame::resume()
{
}

void GameStateEndGame::init()
{
	background = new sf::Sprite();
	background->setTexture(*DATA->getTexture("backgroundEndGame"));
	background->setOrigin(background->getGlobalBounds().width / 2, background->getGlobalBounds().height / 2);
	background->setPosition(screenWidth / 2, screenHeight / 2);

	ani = new Animation();
	ani = LP->getWinner()->getAnimation();
	ani->setScale(1.5, 1.5);
	ani->setStopEndFrame(false);
	ani->setPosition(screenWidth / 2, screenHeight / 2 - ani->getGlobalBounds().height / 2 + 50);
}

void GameStateEndGame::update(float deltaTime)
{
	ani->Update(deltaTime);
}

void GameStateEndGame::render(sf::RenderWindow* window)
{
	window->draw(*background);
	window->draw(*ani);
}
