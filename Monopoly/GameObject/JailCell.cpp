#include "JailCell.h"

JailCell::JailCell()
{
}

void JailCell::init()
{
	setTexture("cellJail");
	cell.setOrigin((sf::Vector2f)cell.getTexture()->getSize() / 2.f);
}

void JailCell::update(float deltaTime)
{

}

void JailCell::render(sf::RenderWindow* window)
{
	window->draw(cell);
}

sf::Vector2f JailCell::getSize()
{
	return (sf::Vector2f)cell.getTexture()->getSize();
}

sf::Vector2f JailCell::getPosition()
{
	return cell.getPosition();
}

void JailCell::setPosition(sf::Vector2f position)
{
	cell.setPosition(position);
}

void JailCell::setTexture(std::string name)
{
	cell.setTexture(*DATA->getTexture("cell/" + name));
}

void JailCell::setPrice(int priceInt)
{
}

int JailCell::getPrice()
{
	return 0;
}

void JailCell::setColor(COLOR color)
{
}

void JailCell::setOwner(OWNER owner, int property)
{
}

OWNER JailCell::getOwner()
{
	return OWNER();
}

CELLTYPE JailCell::getCellType()
{
	return CELLTYPE::JAIL;
}
