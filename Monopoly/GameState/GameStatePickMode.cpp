#include"GameStatePickMode.h"
#include "../GameObject/ListPlayers.h"
GameStatePickMode::GameStatePickMode()
{
}

GameStatePickMode::~GameStatePickMode()
{
	if (background != nullptr)delete background;
	for (auto it : listButton) {
		if (it != nullptr) delete it;
	}
	listButton.clear();
	delete this;
}

void GameStatePickMode::exit()
{
}

void GameStatePickMode::pause()
{
}

void GameStatePickMode::resume()
{
}

void GameStatePickMode::init()
{
	GameButton* button = nullptr;
	// back
	button = new GameButton();
	button->init("backButton");
	button->setSize((sf::Vector2f)button->getTexture()->getSize());
	button->setOrigin(button->getSize() / 2.f);
	button->setFunc([]() {GameStateMachine::getInstance()->popState();});
	button->setPosition(screenWidth/2,screenHeight/2 + button->getSize().y * 1.5);
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

	// pvp
	button = new GameButton();
	button->init("pvpButton");
	button->setSize((sf::Vector2f)button->getTexture()->getSize());
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 - button->getSize().x / 1.5, screenHeight / 2);
	button->setFunc([]() {GameStateMachine::getInstance()->pushState(GAMEPLAY); });
	listButton.push_back(button);

	//pve
	button = new GameButton();
	button->init("pveButton");
	button->setSize((sf::Vector2f)button->getTexture()->getSize());
	button->setOrigin(button->getSize() / 2.f);
	button->setPosition(screenWidth / 2 + button->getSize().x / 1.5, screenHeight / 2);
	button->setFunc([]() {GameStateMachine::getInstance()->pushState(GAMEPLAY); LP->setComputer(3);});
	listButton.push_back(button);

	// background
	background = new sf::Sprite();
	background->setTexture(*DATA->getTexture("backgroundMenu"));
	background->setOrigin((sf::Vector2f)background->getTexture()->getSize() / 2.f);
	background->setPosition(screenWidth / 2, screenHeight / 2);
}

void GameStatePickMode::update(float deltaTime)
{
	for (auto it : listButton) {
		it->update(deltaTime);
	}
}

void GameStatePickMode::render(sf::RenderWindow* window)
{
	window->draw(*background);
	for (auto it : listButton) {
		it->render(window);
	}
}
