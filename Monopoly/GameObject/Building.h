#pragma once
#include "Property.h"
class Building : public Property {
private:
	static float priceCoefficient;
public:
	Building();
	void init();
	void update(float deltaTime);
	void render(sf::RenderWindow* window);
	int getPrice();
	void setPrice(int priceInt);
	OWNER getOwner();
	void setOwner(OWNER owner);
	sf::Vector2f getPosition();
	void setPosittion(sf::Vector2f position);
};
