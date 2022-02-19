#include "DiceRoll.h"

DiceRoll::DiceRoll()
{
}

DiceRoll::DiceRoll(sf::Vector2f position)
{
	this->position = position;
}

DiceRoll::~DiceRoll()
{
	if (font != nullptr) delete font;
	if (text != nullptr) delete text;
	if (diceRoll1 != nullptr) delete diceRoll1;
	if (diceRoll2 != nullptr) delete diceRoll2;
}

void DiceRoll::init()
{
	font = new sf::Font(*DATA->getFont("font"));

	diceRoll1 = new Animation(*DATA->getTexture("dice"), sf::Vector2i(15, 6), 0.1);
	diceRoll1->setPosition(position - sf::Vector2f(diceRoll1->getTextureRect().width / 2, diceRoll1->getTextureRect().height / 2));

	diceRoll2 = new Animation(*DATA->getTexture("dice"), sf::Vector2i(15, 6), 0.1);
	diceRoll2->setPosition(position - sf::Vector2f(diceRoll2->getTextureRect().width / 2, diceRoll2->getTextureRect().height / 2));

	isRolling = false;
	random = 0;
	rand1 = 0;
	rand2 = 0;
	text = new sf::Text();
	text->setFont(*font);
	text->setCharacterSize(100);
	text->setFillColor(sf::Color::Yellow);
	text->setOutlineThickness(4);
	text->setOutlineColor(sf::Color::Black);
}

void DiceRoll::update(float deltaTime)
{
	if (isRolling) {
		diceRoll1->Update(deltaTime);
		diceRoll2->Update(deltaTime);
	}
	if (diceRoll1->getCurrentFrame().x == diceRoll1->getFrameNum().x - 2 || diceRoll2->getCurrentFrame().x == diceRoll2->getFrameNum().x - 2) {
		
		isRolling = false;
		diceRoll1->setStopEndFrame(true);
		diceRoll2->setStopEndFrame(true);
		diceRoll1->setCurrentFrame(sf::Vector2i(diceRoll1->getFrameNum().x - 1, diceRoll1->getCurrentFrame().y));
		diceRoll2->setCurrentFrame(sf::Vector2i(diceRoll2->getFrameNum().x - 1, diceRoll2->getCurrentFrame().y));
		rand1 = 0;
		rand2 = 0;
	}
}

void DiceRoll::render(sf::RenderWindow* window)
{
	window->draw(*diceRoll1);
	window->draw(*diceRoll2);
	if(!isRolling)window->draw(*text);
}

void DiceRoll::setIsRolling(bool isRolling)
{
	this->isRolling = isRolling;
	rand1 = 1 + rand() % 6;
	rand2 = 1 + rand() % 6;
	
	random = rand1 + rand2;
	diceRoll1->setStopEndFrame(false);
	diceRoll2->setStopEndFrame(false);
	diceRoll1->setCurrentFrame(sf::Vector2i(0, rand1 - 1));
	diceRoll2->setCurrentFrame(sf::Vector2i(0, rand2 - 1));
	text->setString(std::to_string(random));
	text->setOrigin(text->getGlobalBounds().width / 2, text->getGlobalBounds().height / 2);
	text->setPosition(position + sf::Vector2f(0,  - text->getGlobalBounds().height /* - diceRoll1->getLocalBounds().height*/));
	DATA->getMusic("roll")->setLoop(true);
	DATA->playMusic("roll");
}

void DiceRoll::setRandom(int random)
{
	this->random = random;
}

int DiceRoll::getRandom()
{
	int tmp = random;
	random = 0;
	DATA->getMusic("roll")->stop();
	return tmp;
}

bool DiceRoll::getIsRolling()
{
	return this->isRolling;
}

void DiceRoll::setPostion(sf::Vector2f position)
{
	this->position = position;
	diceRoll1->setPosition(position + sf::Vector2f(-diceRoll1->getTextureRect().width / 2, diceRoll1->getTextureRect().height / 2));
	diceRoll2->setPosition(position + sf::Vector2f(+diceRoll2->getTextureRect().width / 2, diceRoll2->getTextureRect().height / 2));
}
