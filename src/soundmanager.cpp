#include "soundmanager.h"

SoundManager::SoundManager()
{
    //musics
    //startMenu
    this->files.emplace("dark_winds",DARK_WINDS);
    this->files.emplace("foxie_epic",FOXIE_EPIC);

    //sounds
    //startMenu
    this->files.emplace("click_button",CLICK_BUTTON);
}

void SoundManager::playMusic(std::string musicFile, int volume, bool loop)
{
    if(!this->music.openFromFile(this->files[musicFile]))
        std::cerr<<"unable to load the music file :"<<this->files[musicFile]<<std::endl;

    this->music.setVolume(volume);
    this->music.setLoop(loop);
    this->music.play();
}

void SoundManager::playSound(std::string soundFile, int volume, bool loop)
{
    if(!this->buffer.loadFromFile(this->files[soundFile]))
        std::cerr<<"unable to load the sound file :"<<this->files[soundFile]<<std::endl;
    
    this->sound.setBuffer(this->buffer);
    this->sound.setVolume(volume);
    this->sound.setLoop(loop);
    this->sound.play();
}


void SoundManager::stopMusic()
{
    this->music.stop();
}

SoundManager::~SoundManager()
{

}

