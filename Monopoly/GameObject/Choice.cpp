#include "Choice.h"

Choice::Choice()
{
	choice = 2;
}

Choice::~Choice()
{
}

void Choice::init()
{
	message.init();
	message.setMessage("DO YOU WANT TO BUY THIS CELL?");

	GameButton* button = nullptr;
	// yes
	button = new GameButton();
	button->init("yesButton");
	button->setFunc([]() {CHOICE->setChoice(1);});
	listButtons.push_back(button);
	// no
	button = new GameButton();
	button->init("noButton");
	button->setFunc([]() {CHOICE->setChoice(0);});
	listButtons.push_back(button);
}

void Choice::update(float deltaTime)
{
	for (auto it : listButtons) it->update(deltaTime);
}

void Choice::render(sf::RenderWindow* window)
{
	message.render(window);
	for (auto it : listButtons)it->render(window);
}

void Choice::setPosition(sf::Vector2f position)
{
	message.setPosition(position);
	listButtons[0]->setPosition(position + sf::Vector2f(-listButtons[0]->getSize().x, 250/2 + listButtons[0]->getSize().y));
	listButtons[1]->setPosition(position + sf::Vector2f(+listButtons[1]->getSize().x, 250/2 + listButtons[1]->getSize().y));
}

int Choice::getChoice()
{
	int tmp = choice;
	choice = 2;
	return tmp;
}

void Choice::setChoice(int choice)
{
	this->choice = choice;
}

void Choice::setMessage(std::string message)
{
	this->message.setMessage(message);
}
