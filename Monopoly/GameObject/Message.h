#pragma once
#include "../GameManager/ResourceManager.h"

class Message {
private:
	sf::Text text;
	sf::Sprite sprite;
public:
	Message();
	virtual ~Message();

	void init();
	void update(float deltaTime);
	void render(sf::RenderWindow* window);

	void setMessage(std::string message);

	void setPosition(sf::Vector2f position);
	
	/*sf::Vector2f getSize();*/
};