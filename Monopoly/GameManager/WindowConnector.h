#pragma once
#include "Singleton.h"
#include "SFML/Graphics.hpp"
class WindowConnector : public Singleton<WindowConnector> {
private:
    sf::RenderWindow* window;
public:
    WindowConnector();

    void setWindow(sf::RenderWindow* window);

    sf::RenderWindow* getWindow();
};

