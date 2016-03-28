#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <SFML/Audio.hpp>
#include <iostream>
#include <string.h>

class SoundManager
{
private:

    //int musicType;
    //int soundType;
    std::vector<std::string> soundFiles;
    std::vector<std::string> musicFiles;
    sf::Music music;
    sf::SoundBuffer buffer;
    sf::Sound sound;

public:

    SoundManager();

    void playMusic(int musicType, int volume, bool loop);
    void playSound(int soundType, int volume, bool loop);

    void stopMusic();

    ~SoundManager();

};

#endif // SOUNDMANAGER_H
