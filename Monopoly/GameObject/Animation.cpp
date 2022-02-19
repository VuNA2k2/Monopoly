#include "Animation.h"

Animation::Animation(const sf::Texture& texture, const sf::Vector2i& frameNum, float frameTime)
    : Sprite(texture), frameNum(frameNum), frameTime(frameTime) {
    this->setTexture(texture);
    currentFrame = sf::Vector2i(0, 0);
    currentTime = 0;
    calculateRectSize();
    calulateRectUV();
    applyRect();
    this->setOrigin((sf::Vector2f)size / 2.f);
    stopAtEndFrame = false;
}

Animation::Animation()
{
}

const sf::Vector2i& Animation::getFrameNum() const {
    return frameNum;
}

const sf::Vector2i& Animation::getCurrentFrame() const {
    return currentFrame;
}

void Animation::calculateRectSize() {
    size = sf::Vector2i(this->getTexture()->getSize().x / frameNum.x, this->getTexture()->getSize().y / frameNum.y);
}

void Animation::calulateRectUV() {
    rectUV = sf::Vector2i(currentFrame.x * size.x, currentFrame.y * size.y);
}

void Animation::applyRect() {
    rect = sf::IntRect(rectUV, size);
    this->setTextureRect(rect);
}

void Animation::Update(float deltaTime) {
    if (stopAtEndFrame == true) {
        setFrame(sf::Vector2i(frameNum.x - 1, currentFrame.y));
        currentFrame.x = -1;
        return;
    }
    currentTime += deltaTime;
    if (currentTime >= frameTime) {
        currentFrame.x++;
        if (currentFrame.x == frameNum.x - 1) {
            currentFrame.x -= (frameNum.x -1) ;
        }
        calulateRectUV();
        applyRect();
        currentTime -= frameTime;
    }
}

void Animation::reset() {
    currentFrame.x = 0;
    currentTime = 0;
}

void Animation::setStopEndFrame(bool stop) {
    stopAtEndFrame = stop;
}

bool Animation::getStopAtEndFrame()
{
    return stopAtEndFrame;
}

void Animation::setCurrentFrame(const sf::Vector2i& currentFrame) {
    Animation::currentFrame = currentFrame;
    calulateRectUV();
    applyRect();
}

void Animation::nextFrame() {
    currentFrame.y++;
    if (currentFrame.y == frameNum.y) currentFrame.y = 0;
    calulateRectUV();
    applyRect();
}

void Animation::setFrame(sf::Vector2i frame)
{
    currentFrame = frame;
    calulateRectUV();
    applyRect();
}


