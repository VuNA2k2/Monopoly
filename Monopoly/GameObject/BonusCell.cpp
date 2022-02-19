#include "BonusCell.h"


BonusCell::BonusCell()
{
}

void BonusCell::init()
{
	setTexture("cellBonus");
	cell.setOrigin((sf::Vector2f)cell.getTexture()->getSize() / 2.f);
}

void BonusCell::update(float deltaTime)
{
}

void BonusCell::render(sf::RenderWindow* window)
{
	window->draw(cell);
}

sf::Vector2f BonusCell::getSize()
{
	return (sf::Vector2f)cell.getTexture()->getSize();
}

sf::Vector2f BonusCell::getPosition()
{
	return cell.getPosition();
}

void BonusCell::setPosition(sf::Vector2f position)
{
	cell.setPosition(position);
}

void BonusCell::setTexture(std::string name)
{
	cell.setTexture(*DATA->getTexture("cell/" + name));
}

void BonusCell::setPrice(int priceInt)
{
}

int BonusCell::getPrice()
{
	return 0;
}

void BonusCell::setColor(COLOR color)
{
}

void BonusCell::setOwner(OWNER owner, int property)
{
}

OWNER BonusCell::getOwner()
{
	return OWNER();
}

CELLTYPE BonusCell::getCellType()
{
	return CELLTYPE::BONUS;
}
