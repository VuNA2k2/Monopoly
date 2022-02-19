#include "GameButton.h"
#include "DiceRoll.h"
#include "Choice.h"
GameButton::GameButton()
{
	_isPress = false;
}

GameButton::~GameButton()
{
}

void GameButton::init(std::string texture)
{
	this->setTexture(DATA->getTexture("button/" + texture));
	this->setSize((sf::Vector2f)this->getTexture()->getSize());
	this->setOrigin(this->getSize() / 2.f);
}

void GameButton::update(float deltaTime)
{
	touchEvent();
}

void GameButton::render(sf::RenderWindow* window)
{
	window->draw(*this);
}

void GameButton::touchEvent()
{
	if (this->getGlobalBounds().contains((sf::Vector2f)sf::Mouse::getPosition(*WindowConnector::getInstance()->getWindow()))) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			DATA->playSound("roll");
			Sleep(200);
			Func();
			_isPress = true;
		}
	}
}

bool GameButton::isPress()
{
	return _isPress;
}

void GameButton::setFunc(void(*Func)())
{
	this->Func = Func;
}
