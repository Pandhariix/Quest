#include "soundmanager.h"

SoundManager::SoundManager()
{
    this->musicFiles.resize(1);
    this->soundFiles.resize(1);

    //define the music files
    //startMenu
    this->musicFiles[0] = "Musics/StartMenu/Hero_Immortal.flac";

    //define the sound files
    //button sound
    this->soundFiles[0] = "Sounds/StartMenu/ClickButton.wav";

}

void SoundManager::playMusic(int musicType, int volume, bool loop)
{
    if(!this->music.openFromFile(this->musicFiles[musicType]))
        std::cerr<<"unable to load the music file :"<<this->musicFiles[musicType]<<std::endl;

    this->music.setVolume(volume);
    this->music.setLoop(loop);
    this->music.play();
}

void SoundManager::playSound(int soundType, int volume, bool loop)
{

    //test to know if all the sounds are defined
    if(soundType >= this->soundFiles.size())
    {
        std::cerr<<"the sound type : "<<soundType<<" does not exist"<<std::endl;
    }

    this->buffer.loadFromFile(this->soundFiles[soundType]);
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

