#include "TaxCell.h"


TaxCell::TaxCell()
{
	priceInt = 0;
}

void TaxCell::init()
{
	setTexture("cellTax");
	cell.setOrigin((sf::Vector2f)cell.getTexture()->getSize() / 2.f);
}

void TaxCell::update(float deltaTime)
{
}

void TaxCell::render(sf::RenderWindow* window)
{
	window->draw(cell);
}

sf::Vector2f TaxCell::getSize()
{
	return (sf::Vector2f)cell.getTexture()->getSize();
}

sf::Vector2f TaxCell::getPosition()
{
	return cell.getPosition();
}

void TaxCell::setPosition(sf::Vector2f position)
{
	cell.setPosition(position);
}

void TaxCell::setTexture(std::string name)
{
	cell.setTexture(*DATA->getTexture("cell/" + name));
}

void TaxCell::setPrice(int priceInt)
{
	this->priceInt = priceInt;
}

int TaxCell::getPrice()
{
	return this->priceInt;
}

void TaxCell::setColor(COLOR color)
{
}

void TaxCell::setOwner(OWNER owner, int property)
{
}

OWNER TaxCell::getOwner()
{
	return OWNER();
}

CELLTYPE TaxCell::getCellType()
{
	return CELLTYPE::TAX;
}
