#include "ResourceManager.h"

ResourceManager::ResourceManager() {
    path = "DATA/";
    texturePath = path + "Image/";
    fontPath = path + "Font/";
    soundPath = path + "Sound/";
    musicPath = path + "Music/";
    allowSound = true;
}

ResourceManager::~ResourceManager() {
    for (auto it : mapTexture) {
        if (it.second != nullptr) {
            delete it.second;
        }
    }
    for (auto it : mapFont) {
        if (it.second != nullptr) {
            delete it.second;
        }
    }
    for (auto it : mapSound) {
        if (it.second != nullptr) {
            delete it.second;
        }
    }
    for (auto it : mapMusic) {
        if (it.second != nullptr) {
            delete it.second;
        }
    }
    mapTexture.clear();
    mapFont.clear();
    mapSound.clear();
    mapMusic.clear();
}

void ResourceManager::addTexture(std::string name) {
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(texturePath + name + ".png");

    auto it = mapTexture.find(name);
    if (it != mapTexture.end()) {
        return;
    }
    mapTexture.insert(std::pair<std::string, sf::Texture*>(name, texture));
}

void ResourceManager::removeTexture(std::string name) {
    auto it = mapTexture.find(name);
    if (it == mapTexture.end()) {
        return;
    }
    if (it->second != nullptr) delete it->second;
    mapTexture.erase(it);
}

sf::Texture* ResourceManager::getTexture(std::string name) {
    auto it = mapTexture.find(name);
    if (it != mapTexture.end()) return it->second;
    sf::Texture* texture = new sf::Texture();
    texture->loadFromFile(texturePath + name + ".png");
    mapTexture.insert(std::pair<std::string, sf::Texture*>(name, texture));
    return texture;
}

void ResourceManager::addFont(std::string name) {
    sf::Font* font = new sf::Font();
    font->loadFromFile(fontPath + name + ".ttf");

    auto it = mapFont.find(name);
    if (it != mapFont.end()) {
        return;
    }
    mapFont.insert(std::pair<std::string, sf::Font*>(name, font));
}

void ResourceManager::removeFont(std::string name) {
    auto it = mapFont.find(name);
    if (it == mapFont.end()) {
        return;
    }
    if (it->second != nullptr) delete it->second;
    mapFont.erase(it);
}

sf::Font* ResourceManager::getFont(std::string name) {
    auto it = mapFont.find(name);
    if (it != mapFont.end()) return it->second;
    sf::Font* font = new sf::Font();
    font->loadFromFile(fontPath + name + ".ttf");
    mapFont.insert(std::pair<std::string, sf::Font*>(name, font));
    return font;
}

void ResourceManager::addSound(std::string name)
{
    sf::Sound* sound = new sf::Sound();
    sf::SoundBuffer* buffer = new sf::SoundBuffer();
    buffer->loadFromFile(soundPath + name + ".wav");
    sound->setBuffer(*buffer);

    auto it = mapSound.find(name);
    if (it != mapSound.end()) {
        return;
    }
    mapSound.insert(std::pair<std::string, sf::Sound*>(name, sound));
}

void ResourceManager::removeSound(std::string name)
{
    auto it = mapSound.find(name);
    if (it == mapSound.end()) {
        return;
    }
    if (it->second != nullptr) delete it->second;
    mapSound.erase(it);
}

sf::Sound* ResourceManager::getSound(std::string name)
{
    auto it = mapSound.find(name);
    if (it != mapSound.end()) return it->second;
    sf::Sound* sound = new sf::Sound();
    sf::SoundBuffer* buffer = new sf::SoundBuffer();
    buffer->loadFromFile(soundPath + name + ".wav");
    sound->setBuffer(*buffer);
    mapSound.insert(std::pair<std::string, sf::Sound*>(name, sound));
    return sound;
}

void ResourceManager::addMusic(std::string name)
{
    sf::Music* music = new sf::Music();
    music->openFromFile(musicPath + name + ".wav");

    auto it = mapMusic.find(name);
    if (it != mapMusic.end()) {
        return;
    }
    mapMusic.insert(std::pair<std::string, sf::Music*>(name, music));
}

void ResourceManager::removeMusic(std::string name)
{
    auto it = mapMusic.find(name);
    if (it == mapMusic.end()) {
        return;
    }
    if (it->second != nullptr) delete it->second;
    mapMusic.erase(it);
}

sf::Music* ResourceManager::getMusic(std::string name)
{
    auto it = mapMusic.find(name);
    if (it != mapMusic.end()) return it->second;
    sf::Music* music = new sf::Music();
    music->openFromFile(musicPath + name + ".wav");
    mapMusic.insert(std::pair<std::string, sf::Music*>(name, music));
    return music;
}

void ResourceManager::playMusic(std::string name)
{
    if (allowSound) DATA->getMusic(name)->play();
}

void ResourceManager::playSound(std::string name)
{
    if (allowSound) DATA->getSound(name)->play();
}

void ResourceManager::setAllowSound(bool allow)
{
    allowSound = allow;
}