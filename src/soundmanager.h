#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Audio.hpp>
#include <iostream>
#include <string.h>
#include <map.h>

//musics
#define DARK_WINDS "ressources/musics/menus/DarkWinds.OGG"
#define FOXIE_EPIC "ressources/musics/menus/FoxieEpic.OGG"

//sounds
#define CLICK_BUTTON "ressources/sounds/menus/ClickButton.wav"

class SoundManager
{
private:

    std::map<std::string,std::string> files;
    sf::Music music;
    sf::SoundBuffer buffer;
    sf::Sound sound;

public:

    SoundManager();

    void playMusic(std::string musicFile, int volume, bool loop);
    void playSound(std::string soundFile, int volume, bool loop);

    void stopMusic();

    ~SoundManager();

};

#endif // SOUNDMANAGER_H
