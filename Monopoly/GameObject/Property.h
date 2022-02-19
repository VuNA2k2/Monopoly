#pragma once
#include "../GameManager/ResourceManager.h"

class Property {
protected:
	int priceInt;
	sf::Sprite sprice;
	OWNER owner;
	sf::Vector2f position;
public:
	Property() {};
	virtual void init() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void render(sf::RenderWindow* window) = 0;
	virtual int getPrice() = 0;
	virtual void setPrice(int priceInt) = 0;
	virtual OWNER getOwner() = 0;
	virtual void setOwner(OWNER owner) = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual void setPosittion(sf::Vector2f position) = 0;
};