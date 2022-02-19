#include "House.h"

House::House()
{
}
float House::priceCoefficient = 1.5f;
void House::init()
{
	this->owner = ONULL;
	priceInt = 0;
	sprice.setTexture(*DATA->getTexture("house/houseRed"));
	sprice.setScale(sf::Vector2f(0.5, 0.5));
	sprice.setOrigin(sf::Vector2f(sprice.getTexture()->getSize().x, sprice.getTexture()->getSize().y) / 2.f);
}

void House::update(float deltaTime)
{
	
}

void House::render(sf::RenderWindow* window)
{
	if (owner != ONULL)window->draw(sprice);
}

int House::getPrice()
{
	return this->priceInt;
}

void House::setPrice(int priceInt)
{
	this->priceInt = priceInt * priceCoefficient;
}

OWNER House::getOwner()
{
	return this->owner;
}

void House::setOwner(OWNER owner)
{
	this->owner = owner;
	switch (this->owner)
	{
	case RED:
		sprice.setTexture(*DATA->getTexture("house/houseRed"));
		break;
	case BLUE:
		sprice.setTexture(*DATA->getTexture("house/houseBlue"));
		break;
	case YELLOW:
		sprice.setTexture(*DATA->getTexture("house/houseYellow"));
		break;
	case CYAN:
		sprice.setTexture(*DATA->getTexture("house/houseCyan"));
		break;
	default:
		priceInt = 0;
		break;
	}
}

sf::Vector2f House::getPosition()
{
	return this->position;
}

void House::setPosittion(sf::Vector2f position)
{
	this->position = position;
	sprice.setPosition(position);
}
