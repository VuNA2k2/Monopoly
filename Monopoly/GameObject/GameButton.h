#pragma once
#include "../GameManager/WindowConnector.h"
#include "../GameManager/ResourceManager.h"
class GameButton :public sf::RectangleShape {
private:
	void(*Func)();
	bool _isPress;
public:
	GameButton();
	~GameButton();

	void init(std::string texture);
	void update(float deltaTime);
	void render(sf::RenderWindow* window);

	void touchEvent();
	bool isPress();

	void setFunc(void (*Func)());
};