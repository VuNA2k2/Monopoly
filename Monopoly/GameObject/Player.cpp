#include "Player.h"
#include "ListPlayers.h"
#include "MatrixCells.h"
#include "Choice.h"
Player::Player()
{
	currentState = WAIT;
}

void Player::init()
{
	ani = new Animation(*DATA->getTexture("charactor"), sf::Vector2i(5, 4), 0.15f);
	ani->setScale(0.5, 0.5);
	currentCell = 0;
	nextCell = 0;
	owner = RED;
	ani->setPosition(MatrixCells::getInstance()->getPositionAtCell(currentCell) - sf::Vector2f(0,ani->getTextureRect().height / 2 * ani->getScale().x));
	ani->setStopEndFrame(true);
	currentState = WAIT;
	currentTime = 0;

	moneyInt = 100000;
	moneyText.setFont(*DATA->getFont("font"));
	moneyText.setCharacterSize(48);
	moneyText.setFillColor(sf::Color::Black);
	moneyText.setString(std::to_string(moneyInt));
	moneyText.setOrigin(moneyText.getGlobalBounds().width / 2, moneyText.getGlobalBounds().height / 2);
	isDie = false;
	jail = false;
	isPlayMusic = false;
	isComputer = false;
	DATA->getMusic("run")->setVolume(20);
}

void Player::update(float deltaTime)
{ 
	if (this->moneyInt > 0) {
		switch (currentState)
		{
		case WAIT:
			if (isComputer) {
				Dice->setIsRolling(true);
				currentState = ROLL;
			}
			else {
				if (Dice->getIsRolling()) {
					currentState = ROLL;
					currentTime = 0;
				}
				currentTime += deltaTime;
				if (currentTime >= 10.f) {
					Dice->setIsRolling(true);
					currentTime = 0;
				}
			}
			break;
		case ROLL:
			Dice->update(deltaTime);
			if (!Dice->getIsRolling()) {
				goTo(nextCell + Dice->getRandom());
				currentState = RUN;
			}
			break;
		case RUN:
			ani->setStopEndFrame(currentCell == nextCell);
			ani->Update(deltaTime);
			if (isPlayMusic == false) {
				DATA->playMusic("run");
				//DATA->getMusic("background")->stop();
				isPlayMusic = true;
			}
			// stop
			if (currentCell == nextCell) {
				currentCell = nextCell;
				nextCell = currentCell;
				isPlayMusic = false;
				DATA->getMusic("run")->stop();
				//DATA->playMusic("background");
				//player->setStopEndFrame(true);
				currentState = SELL;
				return;
			}
			// loop
			if (currentCell >= 39) {
				currentCell -= 40;
				nextCell -= 40;
			}

			// check collision
			if (currentCell < 10 && currentCell >= 0 && ani->getPosition().x <= MC->getPositionAtCell(currentCell + 1).x && ani->getPosition().y + ani->getTextureRect().height / 2 * ani->getScale().x <= MC->getPositionAtCell(currentCell + 1).y) {
				currentCell++;
			}
			else if (currentCell < 20 && currentCell >= 10 && ani->getPosition().x >= MC->getPositionAtCell(currentCell + 1).x && ani->getPosition().y + ani->getTextureRect().height / 2 * ani->getScale().x <= MC->getPositionAtCell(currentCell + 1).y) {
				currentCell++;
			}
			else if (currentCell < 30 && currentCell >= 20 && ani->getPosition().x >= MC->getPositionAtCell(currentCell + 1).x && ani->getPosition().y + ani->getTextureRect().height / 2 * ani->getScale().x >= MC->getPositionAtCell(currentCell + 1).y) {
				currentCell++;
			}
			else if ((currentCell == -1 || currentCell < 40 && currentCell >= 30) && ani->getPosition().x <= MC->getPositionAtCell(currentCell + 1).x && ani->getPosition().y + ani->getTextureRect().height / 2 * ani->getScale().x >= MC->getPositionAtCell(currentCell + 1).y) {
				currentCell++;
			}

			// move
			aimDir = sf::Vector2f(0, 0);
			aimDirNorm = sf::Vector2f(0, 0);
			if (currentCell != 39 && currentCell != -1) aimDir = MC->getPositionAtCell(currentCell + 1) - MC->getPositionAtCell(currentCell);
			else aimDir = MC->getPositionAtCell(0) - MC->getPositionAtCell(39);
			aimDirNorm = aimDir / (float)sqrt(pow(aimDir.x, 2) + pow(aimDir.y, 2));
			ani->move(aimDirNorm);
			break;
		case BUY:
			choice = SHOP->getYourChoice();
			if (isComputer) choice = rand() % 10 + 1;
			currentTime += deltaTime;
			if (currentTime >= 10.f) {
				currentState = SNULL;
				currentTime = 0;
			}
			SHOP->update(deltaTime);
			switch (choice % 4)
			{
			case 3:
				LP->setMoneyForOwner(MC->getOwnerAtCell(currentCell), LP->getMoneyForOwner(MC->getOwnerAtCell(currentCell)) + MC->getPriceAtCell(currentCell) * 8 / 10);
				MC->setOwnerAtCell(currentCell, this->getOwner(), 0);
				MC->setOwnerAtCell(currentCell, this->getOwner(), 1);
				MC->setOwnerAtCell(currentCell, this->getOwner(), 2);
				this->setMoney(this->moneyInt - MC->getPriceAtCell(currentCell));
				currentState = SNULL;
				currentTime = 0;
				break;
			case 2:
				LP->setMoneyForOwner(MC->getOwnerAtCell(currentCell), LP->getMoneyForOwner(MC->getOwnerAtCell(currentCell)) + MC->getPriceAtCell(currentCell) * 8 / 10);
				MC->setOwnerAtCell(currentCell, this->getOwner(), 2);
				MC->setOwnerAtCell(currentCell, this->getOwner(), 1);
				this->setMoney(this->moneyInt - MC->getPriceAtCell(currentCell));
				currentState = SNULL;
				currentTime = 0;
				break;
			case 1:
				LP->setMoneyForOwner(MC->getOwnerAtCell(currentCell), LP->getMoneyForOwner(MC->getOwnerAtCell(currentCell)) + MC->getPriceAtCell(currentCell) * 8 / 10);
				MC->setOwnerAtCell(currentCell, this->getOwner(), 2);
				this->setMoney(this->moneyInt - MC->getPriceAtCell(currentCell));
				currentState = SNULL;
				currentTime = 0;
				break;
			default:
				break;
			}
			break;
		case SELL:
			switch (MC->getCell(currentCell)->getCellType())
			{
			case START:
				setMoney(this->moneyInt + 200);
				currentState = SNULL;
				break;
			case TAX:
				currentTime += deltaTime;
				if (currentTime >= 2.f) {
					currentState = SNULL;
					currentTime = 0;
					setMoney(this->moneyInt - this->moneyInt / 10);
				}
				break;
			case BUS:
				currentState = SNULL;
				break;
			case JAIL:
				currentTime += deltaTime;
				if (currentTime >= 2.f) {
					currentState = SNULL;
					currentTime = 0;
					jail = true;
				}
				break;
			case PROPERTY:
				if (MC->getOwnerAtCell(currentCell) != ONULL) {
					if (this->getOwner() != MC->getOwnerAtCell(currentCell)) {
						this->setMoney(this->moneyInt - MC->getPriceAtCell(currentCell));
						LP->setMoneyForOwner(MC->getOwnerAtCell(currentCell), LP->getMoneyForOwner(MC->getOwnerAtCell(currentCell)) + MC->getPriceAtCell(currentCell)*8/10);
						currentState = CHOSE;
					}
					else currentState = SNULL;
				}
				else {
					if (MC->getPriceAtCell(currentCell) < this->getMoney()) {
						Choice::getInstance()->update(deltaTime);
						choice = Choice::getInstance()->getChoice();
						if (isComputer) choice = rand() % 3;
						switch (choice)
						{
						case 0:
							currentState = SNULL;
							currentTime = 0;
							break;
						case 1:
							currentState = BUY;
							currentTime = 0;
							break;
						default:
							currentTime += deltaTime;
							if (currentTime >= 10.f) {
								currentState = SNULL;
								currentTime = 0;
							}
							break;
						}
					}
					else currentState = SNULL;
				}
				break;
			case BONUS:
				setMoney(this->moneyInt * 2);
				currentState = SNULL;
				break;
			default:
				break;
			}
			break;
		case CHOSE:
			if (this->moneyInt >= MC->getPriceAtCell(currentCell)) {
				Choice::getInstance()->update(deltaTime);
				choice = Choice::getInstance()->getChoice();
				if (isComputer) choice = rand() % 3;
				switch (choice)
				{
				case 0:
					currentState = SNULL;
					currentTime = 0;
					break;
				case 1:
					currentState = BUY;
					currentTime = 0;
					break;
				default:
					currentTime += deltaTime;
					if (currentTime >= 10.f) {
						currentState = SNULL;
						currentTime = 0;
					}
					break;
				}
			}
			else currentState = SNULL;	
			break;
		case SNULL:
			break;
		}
	}
	else currentState = SNULL;
}

void Player::render(sf::RenderWindow* window)
{
	if(this->moneyInt > 0)window->draw(*ani);
	window->draw(moneyText);
}

void Player::goTo(int cell)
{
	if (cell < currentCell) cell += 40;
	nextCell = cell;
	ani->setStopEndFrame(false);
}

int Player::getCurrentCell()
{
	return this->currentCell;
}

int Player::getNextCell()
{
	return nextCell;
}

PSTATE Player::getCurrentState()
{
	return currentState;
}

void Player::setCurrentState(PSTATE state)
{
	this->currentState = state;
}

void Player::setMoney(int moneyInt)
{
	this->moneyInt = moneyInt;
	moneyText.setString(std::to_string(moneyInt));
	moneyText.setOrigin(moneyText.getGlobalBounds().width / 2, moneyText.getGlobalBounds().height / 2);
	switch (this->getOwner())
	{
	case RED:
		moneyText.setPosition(sf::Vector2f(225, 25));
		break;
	case YELLOW:
		moneyText.setPosition(sf::Vector2f(1790, 25));
		break;
	case CYAN:
		moneyText.setPosition(sf::Vector2f(1790, 980));
		break;
	case BLUE:
		moneyText.setPosition(sf::Vector2f(225, 980));
		break;
	default:
		break;
	}
}

int Player::getMoney()
{
	return this->moneyInt;
}

OWNER Player::getOwner()
{
	return owner;
}

void Player::setOwner(OWNER owner)
{
	this->owner = owner;
	ani->setFrame(sf::Vector2i(ani->getCurrentFrame().x,(int) owner));
	switch (this->getOwner())
	{
	case RED:
		moneyText.setPosition(sf::Vector2f(225, 25));
		break;
	case YELLOW:
		moneyText.setPosition(sf::Vector2f(1790, 25));
		break;
	case CYAN:
		moneyText.setPosition(sf::Vector2f(1790, 980));
		break;
	case BLUE:
		moneyText.setPosition(sf::Vector2f(225, 980));
		break;
	default:
		break;
	}
}

bool Player::getJail()
{
	bool tmp = jail;
	jail = false;
	return tmp;
}

Animation* Player::getAnimation()
{
	return this->ani;
}

void Player::setComputer(bool isComputer)
{
	this->isComputer = isComputer;
}
