#include "GameStateIntro.h"
#include "../GameManager/ResourceManager.h"
GameStateIntro::GameStateIntro()
{
	currentTime = 0;
}

GameStateIntro::~GameStateIntro()
{
	if(logo != nullptr) delete logo;
	delete this;
}

void GameStateIntro::exit()
{
	currentTime = 0;
}

void GameStateIntro::pause()
{
}

void GameStateIntro::resume()
{
}

void GameStateIntro::init()
{
	logo = new sf::Sprite();
	logo->setTexture(*DATA->getTexture("logo"));
	logo->setPosition(screenWidth / 2, screenHeight / 2);
	logo->setOrigin((sf::Vector2f) logo->getTexture()->getSize() / 2.f);
	//logo.setColor(sf::Color(100, 100, 100, 1000));
	DATA->playMusic("backgroundMusic");
}

void GameStateIntro::update(float deltaTime)
{
	currentTime += deltaTime;
	if (currentTime >= 3.f) {
		GameStateMachine::getInstance()->changeState(MENU);
	}
	logo->setColor(sf::Color(100, 100, 100, 1000 - currentTime * 75));
}

void GameStateIntro::render(sf::RenderWindow* window)
{
	window->draw(*logo);
}
