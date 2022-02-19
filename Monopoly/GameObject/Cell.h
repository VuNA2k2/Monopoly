#pragma once

#include "../GameManager/ResourceManager.h"
enum CELLTYPE {
	START,
	TAX,
	BUS,
	JAIL,
	PROPERTY,
	BONUS,
};
class Cell {
protected:
	sf::Sprite cell;
public:
	Cell() {};

	virtual void init() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void render(sf::RenderWindow* window) = 0;

	virtual sf::Vector2f getSize() = 0;
	virtual sf::Vector2f getPosition() = 0;
	virtual void setPosition(sf::Vector2f position) = 0;

	virtual void setTexture(std::string name) = 0;

	virtual void setPrice(int priceInt) = 0;
	virtual int getPrice() = 0;

	virtual void setColor(COLOR color) = 0;

	virtual void setOwner(OWNER owner, int property) = 0;
	virtual OWNER getOwner() = 0;

	virtual CELLTYPE getCellType() = 0;
};