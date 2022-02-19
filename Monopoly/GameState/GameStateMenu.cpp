#include "GameStateMenu.h"

GameStateMenu::GameStateMenu()
{
}

GameStateMenu::~GameStateMenu()
{
	if (background != nullptr)delete background;
	for (auto it : listButton) {
		if (it != nullptr) delete it;
	}
	listButton.clear();
	delete this;
}

void GameStateMenu::exit()
{
}

void GameStateMenu::pause()
{
}

void GameStateMenu::resume()
{
}

void GameStateMenu::init()
{
	
	GameButton* button = nullptr;
	// close window
	button = new GameButton();
	button->init("exitButton");
	button->setFunc([]() {WindowConnector::getInstance()->getWindow()->close();});
	button->setPosition(screenWidth - button->getSize().x / 2,button->getSize().y / 2);
	listButton.push_back(button);

	// sound on
	button = new GameButton();
	button->init("musicButtonOn");
	button->setFunc([]() {DATA->setAllowSound(true); });
	button->setPosition(button->getSize().x / 2, button->getSize().y / 2);
	listButton.push_back(button);

	// sound off
	button = new GameButton();
	button->init("musicButtonOff");
	button->setFunc([]() {DATA->setAllowSound(false); });
	button->setPosition(button->getSize().x * 1.5 + 10, button->getSize().y / 2);
	listButton.push_back(button);

	// play
	button = new GameButton();
	button->init("playButton");
	button->setPosition(screenWidth / 2, screenHeight / 2);
	button->setSize((sf::Vector2f)button->getTexture()->getSize());
	button->setOrigin(button->getSize() / 2.f);
	button->setFunc([]() {GameStateMachine::getInstance()->pushState(PICKMODE);});
	listButton.push_back(button);

	// background
	background = new sf::Sprite();

	background->setTexture(*DATA->getTexture("backgroundMenu"));
	background->setOrigin((sf::Vector2f)background->getTexture()->getSize() / 2.f);
	background->setPosition(screenWidth / 2, screenHeight / 2);

}

void GameStateMenu::update(float deltaTime)
{
	for (auto it : listButton) {
		it->update(deltaTime);
	}
}

void GameStateMenu::render(sf::RenderWindow* window)
{
	window->draw(*background);
	for (auto it : listButton) {
		it->render(window);
	}
}
