#pragma once
#include "GameButton.h"
#include <list>
#define SHOP Shop::getInstance()
class Shop : public Singleton<Shop> {
private:
	std::list<GameButton*> gameButton;

	OWNER owner;

	int choice;
public:
	Shop();

	void init();
	void update(float deltaTime);
	void render(sf::RenderWindow* window);

	int getYourChoice();
	void setYourChoice(int choice);
}; 