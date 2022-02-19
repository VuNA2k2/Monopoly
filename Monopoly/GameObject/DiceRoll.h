#pragma once
#include "../GameManager/ResourceManager.h"
#include "Animation.h"
#define Dice DiceRoll::getInstance()
class DiceRoll : public Singleton <DiceRoll>
{
private:
	sf::Font* font;
	sf::Text* text;
	Animation *diceRoll1, *diceRoll2;
	int random;
	int rand1;
	int rand2;
	bool isRolling;
	sf::Vector2f position;
public:
	DiceRoll();
	DiceRoll(sf::Vector2f position);
	virtual ~DiceRoll();
	void init();
	void update(float deltaTime);
	void render(sf::RenderWindow* window);

	void setIsRolling(bool isRolling);
	void setRandom(int random);
	int getRandom();
	bool getIsRolling();

	void setPostion(sf::Vector2f position);
};

