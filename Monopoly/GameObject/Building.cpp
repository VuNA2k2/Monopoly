#include "Building.h"

Building::Building()
{
}
float Building::priceCoefficient = 2.f;
void Building::init()
{
	this->owner = ONULL;
	priceInt = 0;
	sprice.setTexture(*DATA->getTexture("building/buildingRed"));
	sprice.setScale(sf::Vector2f(0.5, 0.5));
	sprice.setOrigin(sf::Vector2f(sprice.getTexture()->getSize().x, sprice.getTexture()->getSize().y) / 2.f);
}

void Building::update(float deltaTime)
{

}

void Building::render(sf::RenderWindow* window)
{
	if (owner != ONULL)window->draw(sprice);
}

int Building::getPrice()
{
	return this->priceInt;
}

void Building::setPrice(int priceInt)
{
	this->priceInt = priceInt * priceCoefficient;
}

OWNER Building::getOwner()
{
	return this->owner;
}

void Building::setOwner(OWNER owner)
{
	this->owner = owner;
	switch (this->owner)
	{
	case RED:
		sprice.setTexture(*DATA->getTexture("building/buildingRed"));
		break;
	case BLUE:
		sprice.setTexture(*DATA->getTexture("building/buildingBlue"));
		break;
	case YELLOW:
		sprice.setTexture(*DATA->getTexture("building/buildingYellow"));
		break;
	case CYAN:
		sprice.setTexture(*DATA->getTexture("building/buildingCyan"));
		break;
	default:
		priceInt = 0;
		break;
	}
}

sf::Vector2f Building::getPosition()
{
	return this->position;
}

void Building::setPosittion(sf::Vector2f position)
{
	this->position = position;
	sprice.setPosition(position);
}
