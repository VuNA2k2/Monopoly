#pragma once
#include "SFML/Graphics.hpp"

class Animation : public sf::Sprite {
private:
    sf::Vector2i frameNum;
    sf::Vector2i currentFrame;

    float frameTime;
    float currentTime;

    bool stopAtEndFrame;

    sf::IntRect rect;
    sf::Vector2i size;
    sf::Vector2i rectUV;

public:
    Animation(const sf::Texture& texture, const sf::Vector2i& frameNum, float frameTime);
    Animation();
    void calculateRectSize();
    void calulateRectUV();
    void applyRect();
    void setCurrentFrame(const sf::Vector2i& currentFrame);
    void nextFrame();
    void setFrame(sf::Vector2i frame);

    void Update(float deltaTime);
    void reset();
    void setStopEndFrame(bool stop);
    bool getStopAtEndFrame();

    const sf::Vector2i& getFrameNum() const;
    const sf::Vector2i& getCurrentFrame() const;
};