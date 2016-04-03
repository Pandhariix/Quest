#ifndef STARTMENU_H
#define STARTMENU_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
#include <soundmanager.h>
#include <optionsmenu.h>
#include <loadgamemenu.h>

#define START_SCREEN "ressources/images/menus/StartScreen.jpg"

class StartMenu
{
private:

    int width;
    int length;
    std::string name;

    sf::RenderWindow *startMenu;

    SoundManager soundMenu;

    bool start;
    bool loadGame;
    bool options;
    bool exit;

public:

    StartMenu();

    bool getStart();
    bool getLoadGame();
    bool getOptions();
    bool getExit();

    ~StartMenu();
};

#endif // STARTMENU_H
