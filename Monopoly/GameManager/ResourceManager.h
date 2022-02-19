#pragma once
#include "Singleton.h"
#include <map>
#include "string"
#include "../GameObject/GameButton.h"
#include "../GameConfig.h"
#include <Windows.h>
#include "SFML/Audio.hpp"
class ResourceManager : public Singleton<ResourceManager> {
private:
    std::map<std::string, sf::Texture*> mapTexture;
    std::map<std::string, sf::Font*> mapFont;
    std::map<std::string, sf::Sound*> mapSound;
    std::map<std::string, sf::Music*> mapMusic;

    std::string path;
    std::string texturePath;
    std::string fontPath;
    std::string soundPath;
    std::string musicPath;

    bool allowSound;
public:
    ResourceManager();

    ~ResourceManager();

    void addTexture(std::string name);
    void removeTexture(std::string name);
    sf::Texture* getTexture(std::string name);

    void addFont(std::string name);
    void removeFont(std::string name);
    sf::Font* getFont(std::string name);

    void addSound(std::string name);
    void removeSound(std::string name);
    sf::Sound* getSound(std::string name);

    void addMusic(std::string name);
    void removeMusic(std::string name);
    sf::Music* getMusic(std::string name);

    void playMusic(std::string name);
    void playSound(std::string name);
    void setAllowSound(bool allow);
};
