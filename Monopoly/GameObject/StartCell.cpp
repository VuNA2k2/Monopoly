#include "StartCell.h"

StartCell::StartCell()
{
}

void StartCell::init()
{
	setTexture("cellStart");
	cell.setOrigin((sf::Vector2f)cell.getTexture()->getSize() / 2.f);
}

void StartCell::update(float deltaTime)
{
}

void StartCell::render(sf::RenderWindow* window)
{
	window->draw(cell);
}

sf::Vector2f StartCell::getSize()
{
	return (sf::Vector2f)cell.getTexture()->getSize();
}

sf::Vector2f StartCell::getPosition()
{
	return cell.getPosition();
}

void StartCell::setPosition(sf::Vector2f position)
{
	cell.setPosition(position);
}

void StartCell::setTexture(std::string name)
{
	cell.setTexture(*DATA->getTexture("cell/" + name));
}

void StartCell::setPrice(int priceInt)
{
}

int StartCell::getPrice()
{
	return 0;
}

void StartCell::setColor(COLOR color)
{
}

void StartCell::setOwner(OWNER owner, int property)
{
}

OWNER StartCell::getOwner()
{
	return OWNER();
}

CELLTYPE StartCell::getCellType()
{
	return CELLTYPE::START;
}
