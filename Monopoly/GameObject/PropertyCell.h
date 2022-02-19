#pragma once
#include "Cell.h"
#include "Property.h"

class PropertyCell : public Cell {
private:
	int priceInt;
	sf::Text priceText;
	sf::Text name;
	std::vector<Property*> property;
	COLOR color;
	OWNER owner;
	int currentProperty;
public:
	PropertyCell();
	PropertyCell(std::string name);

	void init();
	void update(float deltaTime);
	void render(sf::RenderWindow* window);

	sf::Vector2f getSize();
	sf::Vector2f getPosition();
	void setPosition(sf::Vector2f position);

	void setTexture(std::string name);

	void setPrice(int priceInt);
	int getPrice();

	void setColor(COLOR color);

	void setOwner(OWNER owner, int property);
	OWNER getOwner();

	CELLTYPE getCellType();
};