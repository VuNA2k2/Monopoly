#include "PropertyCell.h"
#include "House.h"
#include "Building.h"
#include "Hotel.h"
PropertyCell::PropertyCell()
{
	init();
}

PropertyCell::PropertyCell(std::string name)
{
	this->name.setString(name);
	init();
}

void PropertyCell::init()
{
	currentProperty = 0;
	this->owner = ONULL;
	priceInt = 0;
	cell.setTexture(*DATA->getTexture("cell/cellRed"));

	cell.setOrigin((sf::Vector2f)cell.getTexture()->getSize() / 2.f);

	// price
	priceText.setFont(*DATA->getFont("font"));
	priceText.setFillColor(sf::Color::Black);
	priceText.setCharacterSize(10);
	priceText.setOrigin(priceText.getGlobalBounds().width / 2, priceText.getGlobalBounds().height / 2);
	priceText.setPosition(getPosition().x, getPosition().y + 20);

	this->name.setFont(*DATA->getFont("font"));
	this->name.setFillColor(sf::Color::Black);
	this->name.setCharacterSize(10);
	this->name.setOrigin(this->name.getGlobalBounds().width / 2, this->name.getGlobalBounds().height / 2);
	this->name.setPosition(getPosition().x, getPosition().y + 10);

	Property* propertyTmp = nullptr;

	propertyTmp = new Hotel();
	propertyTmp->init();
	property.push_back(propertyTmp);

	propertyTmp = new Building();
	propertyTmp->init();
	property.push_back(propertyTmp);

	propertyTmp = new House();
	propertyTmp->init();
	property.push_back(propertyTmp);
}

void PropertyCell::update(float deltaTime)
{
	for (auto it : property) it->update(deltaTime);
}

void PropertyCell::render(sf::RenderWindow* window)
{
	window->draw(cell);
	window->draw(priceText);
	window->draw(name);
	for (auto it : property) it->render(window);
}

sf::Vector2f PropertyCell::getSize()
{
	return (sf::Vector2f)cell.getTexture()->getSize();
}

sf::Vector2f PropertyCell::getPosition()
{
	return cell.getPosition();
}

void PropertyCell::setPosition(sf::Vector2f position)
{
	cell.setPosition(position);
	this->name.setPosition(getPosition().x, getPosition().y + 10);
	priceText.setPosition(getPosition().x, getPosition().y + 20);
	property[2]->setPosittion(sf::Vector2f(getPosition() + sf::Vector2f(33.5,-7.5)));
	property[1]->setPosittion(sf::Vector2f(getPosition() + sf::Vector2f(19.5, -22.75)));
	property[0]->setPosittion(sf::Vector2f(getPosition() + sf::Vector2f(1, -38.75)));
}

void PropertyCell::setTexture(std::string name)
{
	cell.setTexture(*DATA->getTexture("cell/" + name));
}

void PropertyCell::setPrice(int priceInt)
{
	this->priceInt = priceInt;
	for (auto it : property) it->setPrice(this->priceInt);
	for (auto it : property) {
		if (it->getOwner() != ONULL) {
			this->priceInt += it->getPrice();
		}
	}
	priceText.setString(std::to_string(priceInt));
	priceText.setOrigin(priceText.getGlobalBounds().width / 2, priceText.getGlobalBounds().height / 2);
	priceText.setPosition(getPosition().x, getPosition().y + 20);
}

int PropertyCell::getPrice()
{
	return this->priceInt;
}

void PropertyCell::setColor(COLOR color)
{
	this->color = color;
	switch (color)
	{
	case COLOR::red:
		this->setPrice(2500);
		this->setTexture("cellRed");
		break;
	case COLOR::blue:
		this->setPrice(2000);
		this->setTexture("cellBlue");
		break;
	case COLOR::green:
		this->setPrice(1500);
		this->setTexture("cellGreen");
		break;
	case COLOR::yellow:
		this->setPrice(1000);
		this->setTexture("cellYellow");
		break;
	default:
		break;
	}
}

void PropertyCell::setOwner(OWNER owner, int property)
{
	if(property == 3) for(auto it : this->property) this->priceInt -= it->getPrice();
	else {
		this->owner = owner;
		this->property[property]->setOwner(owner);
		this->priceInt += this->property[property]->getPrice();
		priceText.setString(std::to_string(priceInt));
		priceText.setOrigin(priceText.getGlobalBounds().width / 2, priceText.getGlobalBounds().height / 2);
		priceText.setPosition(getPosition().x, getPosition().y + 20);
	}
}

OWNER PropertyCell::getOwner()
{
	return this->owner;
}

CELLTYPE PropertyCell::getCellType()
{
	return CELLTYPE::PROPERTY;
}
