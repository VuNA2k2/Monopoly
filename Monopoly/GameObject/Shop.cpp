#include "Shop.h"

Shop::Shop()
{
}

void Shop::init()
{
	GameButton* btn = nullptr;
	
	choice = 0;

	btn = new GameButton();
	btn->init("buy/buyHouse");
	btn->setSize((sf::Vector2f) btn->getTexture()->getSize());
	btn->setOrigin((sf::Vector2f)btn->getTexture()->getSize() / 2.f);
	btn->setPosition(sf::Vector2f(screenWidth / 2 - btn->getTexture()->getSize().x * 1.5, screenHeight / 2 + btn->getTexture()->getSize().y / 2));
	btn->setFunc([]() { SHOP->setYourChoice(1); });
	gameButton.push_back(btn);

	btn = new GameButton();
	btn->init("buy/buyHouseAndBuilding");
	btn->setSize((sf::Vector2f)btn->getTexture()->getSize());
	btn->setOrigin((sf::Vector2f)btn->getTexture()->getSize() / 2.f);
	btn->setPosition(sf::Vector2f(screenWidth / 2, screenHeight / 2 + btn->getTexture()->getSize().y / 2));
	btn->setFunc([]() { SHOP->setYourChoice(2); });
	gameButton.push_back(btn);

	btn = new GameButton();
	btn->init("buy/buyHouseBuildingAndHotel");
	btn->setSize((sf::Vector2f)btn->getTexture()->getSize());
	btn->setOrigin((sf::Vector2f)btn->getTexture()->getSize() / 2.f);
	btn->setPosition(sf::Vector2f(screenWidth / 2 + btn->getTexture()->getSize().x * 1.5, screenHeight / 2 + btn->getTexture()->getSize().y / 2));
	btn->setFunc([]() { SHOP->setYourChoice(3); });
	gameButton.push_back(btn);
}

void Shop::update(float deltaTime)
{
	for (auto it : gameButton) it->update(deltaTime);
}

void Shop::render(sf::RenderWindow* window)
{
	for (auto it : gameButton) it->render(window);
}

int Shop::getYourChoice()
{
	int tmp = choice;
	choice = 0;
	return tmp;
}

void Shop::setYourChoice(int choice)
{
	this->choice = choice;
}
