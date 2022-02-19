#include "Message.h"

Message::Message()
{
}

Message::~Message()
{
}

void Message::init()
{
	sprite.setTexture(*DATA->getTexture("messageForm"));
	sprite.setOrigin((sf::Vector2f)sprite.getTexture()->getSize() / 2.f);
	text.setFont(*DATA->getFont("font"));
	text.setCharacterSize(72);
	text.setFillColor(sf::Color::Black);
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);

}

void Message::update(float deltaTime)
{
}

void Message::render(sf::RenderWindow* window)
{
	window->draw(sprite);
	window->draw(text);
}

void Message::setMessage(std::string message)
{
	text.setString(message);
	text.setOrigin(text.getGlobalBounds().width / 2, text.getGlobalBounds().height / 2);
}

void Message::setPosition(sf::Vector2f position)
{
	sprite.setPosition(position);
	text.setPosition(position + sf::Vector2f(0,-text.getGlobalBounds().height/2));
}

//sf::Vector2f Message::getSize()
//{
//	return sf::Vector2f(sprite.getTexture()->getSize());
//}
