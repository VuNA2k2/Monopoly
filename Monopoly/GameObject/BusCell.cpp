#include "BusCell.h"


BusCell::BusCell()
{
}

void BusCell::init()
{
	setTexture("cellBus");
	cell.setOrigin((sf::Vector2f)cell.getTexture()->getSize() / 2.f);
}

void BusCell::update(float deltaTime)
{
}

void BusCell::render(sf::RenderWindow* window)
{
	window->draw(cell);
}

sf::Vector2f BusCell::getSize()
{
	return (sf::Vector2f)cell.getTexture()->getSize();
}

sf::Vector2f BusCell::getPosition()
{
	return cell.getPosition();
}

void BusCell::setPosition(sf::Vector2f position)
{
	cell.setPosition(position);
}

void BusCell::setTexture(std::string name)
{
	cell.setTexture(*DATA->getTexture("cell/" + name));
}

void BusCell::setPrice(int priceInt)
{
}

int BusCell::getPrice()
{
	return 0;
}

void BusCell::setColor(COLOR color)
{
}

void BusCell::setOwner(OWNER owner, int property)
{
}

OWNER BusCell::getOwner()
{
	return OWNER();
}

CELLTYPE BusCell::getCellType()
{
	return CELLTYPE::BUS;
}
