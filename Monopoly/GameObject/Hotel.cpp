#include "Hotel.h"

Hotel::Hotel()
{
}
float Hotel::priceCoefficient = 3.f;
void Hotel::init()
{
	this->owner = ONULL;
	priceInt = 0;
	sprice.setTexture(*DATA->getTexture("hotel/hotelRed"));
	sprice.setScale(sf::Vector2f(0.5, 0.5));
	sprice.setOrigin(sf::Vector2f(sprice.getTexture()->getSize().x, sprice.getTexture()->getSize().y) / 2.f);
}

void Hotel::update(float deltaTime)
{

}

void Hotel::render(sf::RenderWindow* window)
{
	if (owner != ONULL)window->draw(sprice);
}

int Hotel::getPrice()
{
	return this->priceInt;
}

void Hotel::setPrice(int priceInt)
{
	this->priceInt = priceInt * priceCoefficient;
}

OWNER Hotel::getOwner()
{
	return this->owner;
}

void Hotel::setOwner(OWNER owner)
{
	this->owner = owner;
	switch (this->owner)
	{
	case RED:
		sprice.setTexture(*DATA->getTexture("hotel/hotelRed"));
		break;
	case BLUE:
		sprice.setTexture(*DATA->getTexture("hotel/hotelBlue"));
		break;
	case YELLOW:
		sprice.setTexture(*DATA->getTexture("hotel/hotelYellow"));
		break;
	case CYAN:
		sprice.setTexture(*DATA->getTexture("hotel/hotelCyan"));
		break;
	default:
		priceInt = 0;
		break;
	}
}

sf::Vector2f Hotel::getPosition()
{
	return this->position;
}

void Hotel::setPosittion(sf::Vector2f position)
{
	this->position = position;
	sprice.setPosition(position);
}
