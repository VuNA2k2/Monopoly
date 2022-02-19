#include "GameStateGamePlay.h"
#include "../GameObject/PropertyCell.h"
#include "../GameObject/Shop.h"
GameStateGamePlay::GameStateGamePlay()
{
}

GameStateGamePlay::~GameStateGamePlay()
{
	if (goToJail != nullptr)delete goToJail;
	if (payYourPropertyTaxes != nullptr)delete payYourPropertyTaxes;
	if (frame != nullptr) delete frame;
	if (background2 != nullptr)delete background2;
	if (background != nullptr)delete background;
	if (roll != nullptr) delete roll;
	for (auto it : buttons) {
		if (it != nullptr)delete it;
	}
	buttons.clear();
	for (auto it : frameBackground) {
		if (it != nullptr) delete it;
	}
	frameBackground.clear();
	Choice::removeInstance();
	DiceRoll::removeInstance();
	MatrixCells::removeInstance();
	ListPlayers::removeInstance();
	delete this;
}

void GameStateGamePlay::exit()
{
}

void GameStateGamePlay::pause()
{
}

void GameStateGamePlay::resume()
{
}

void GameStateGamePlay::init()
{
	DATA->getMusic("backgroundMusic")->stop();
	CHOICE->init();
	CHOICE->setPosition(sf::Vector2f(960, 600));

	//shop
	SHOP->init();
	//backgrond
	background = new sf::Sprite();
	background->setTexture(*DATA->getTexture("background"));
	background2 = new sf::Sprite();
	background2->setTexture(*DATA->getTexture("background2"));
	background2->setScale(0.9, 1);
	background2->setOrigin(sf::Vector2f(background2->getTexture()->getSize().x / 2.f, background2->getTexture()->getSize().y / 2.f));
	background2->setPosition(960, 600);
	//frame
	frame = new sf::Sprite();
	frame->setTexture(*DATA->getTexture("frameGamePlay"));
	//dice
	Dice->init();
	Dice->setPostion(sf::Vector2f((float) screenWidth / 2, (float)screenHeight / 2));
	//cells
	MC->init();
	//players
	LP->init();
	//button
	roll = new GameButton();
	roll->init("rollButton");
	roll->setSize((sf::Vector2f)roll->getTexture()->getSize());
	roll->setOrigin(roll->getSize() / 2.f);
	roll->setPosition(sf::Vector2f(960, 600));
	roll->setFunc([]() {Dice->setIsRolling(true);});
	// frame avatar
	sf::Sprite* sprite = nullptr;

	sprite = new sf::Sprite();
	sprite->setTexture(*DATA->getTexture("frameBackground"));
	sprite->setOrigin((sf::Vector2f)sprite->getTexture()->getSize() / 2.f);
	sprite->setPosition(183.5, 62);
	frameBackground.push_back(sprite);

	sprite = new sf::Sprite();
	sprite->setTexture(*DATA->getTexture("frameBackground"));
	sprite->setOrigin((sf::Vector2f)sprite->getTexture()->getSize() / 2.f);
	sprite->setPosition(1736.5, 62);
	frameBackground.push_back(sprite);

	sprite = new sf::Sprite();
	sprite->setTexture(*DATA->getTexture("frameBackground"));
	sprite->setOrigin((sf::Vector2f)sprite->getTexture()->getSize() / 2.f);
	sprite->setPosition(1736.5, 1018);
	frameBackground.push_back(sprite);

	sprite = new sf::Sprite();
	sprite->setTexture(*DATA->getTexture("frameBackground"));
	sprite->setOrigin((sf::Vector2f)sprite->getTexture()->getSize() / 2.f);
	sprite->setPosition(183.5, 1018);
	frameBackground.push_back(sprite);
	// go to jail
	goToJail = new Message();
	goToJail->init();
	goToJail->setMessage("Go To Jail");
	goToJail->setPosition(sf::Vector2f(screenWidth / 2, screenHeight / 2));
	// pay your property taxes
	payYourPropertyTaxes = new Message();
	payYourPropertyTaxes->init();
	payYourPropertyTaxes->setMessage("Pay your property taxes");
	payYourPropertyTaxes->setPosition(sf::Vector2f(screenWidth / 2, screenHeight / 2));
	DATA->getMusic("background")->setLoop(true);
	DATA->playMusic("background");
}

void GameStateGamePlay::update(float deltaTime)
{
	MatrixCells::getInstance()->update(deltaTime);

	LP->update(deltaTime);

	roll->update(deltaTime);

	//Dice->update(deltaTime);
}

void GameStateGamePlay::render(sf::RenderWindow* window)
{
	window->draw(*background);
	window->draw(*background2);
	window->draw(*frameBackground[LP->getCurrentPlayer()]);
	window->draw(*frame);
	MatrixCells::getInstance()->render(window);
	LP->render(window);
	if(LP->getState() == WAIT)roll->render(window);
	if (LP->getState() != WAIT && LP->getState() != BUY && LP->getState() != SELL)Dice->render(window);
	if ((LP->getState() == SELL || LP->getState() == CHOSE) && MC->getCell(LP->getCurrentCell())->getCellType() == PROPERTY) CHOICE->render(window);
	if (LP->getState() == BUY) SHOP->render(window);
	if (MC->getCell(LP->getCurrentCell())->getCellType() == JAIL && LP->getState() == SELL) goToJail->render(window);
	if (MC->getCell(LP->getCurrentCell())->getCellType() == TAX && LP->getState() == SELL) payYourPropertyTaxes->render(window);
}
