#include "WindowConnector.h"

WindowConnector::WindowConnector() {
    window = nullptr;
}

void WindowConnector::setWindow(sf::RenderWindow* window) {
    this->window = window;
}

sf::RenderWindow* WindowConnector::getWindow() {
    if (window != nullptr) return window;
}
