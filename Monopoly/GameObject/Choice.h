#pragma once
#include "Message.h"
#include "GameButton.h"
#define CHOICE  Choice::getInstance()
class Choice : public Singleton<Choice>{
private:
	Message message;
	std::vector<GameButton*> listButtons;
	int choice;
public:
	Choice();
	virtual ~Choice();

	void init();
	void update(float deltaTime);
	void render(sf::RenderWindow* window);

	void setPosition(sf::Vector2f position);

	int getChoice();
	void setChoice(int choice);

	void setMessage(std::string message);
};