#ifndef STARTMENU_H
#define STARTMENU_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
#include <soundmanager.h>
#include <optionsmenu.h>
#include <loadgamemenu.h>

//images
#define START_SCREEN "ressources/images/menus/StartScreen.jpg"

//buttons
#define BUTTON_START "ressources/images/menus/buttons/start.png"
#define BUTTON_LOAD_GAME "ressources/images/menus/buttons/load_game.png"
#define BUTTON_OPTIONS "ressources/images/menus/buttons/options.png"
#define BUTTON_EXIT "ressources/images/menus/buttons/exit.png"

#define BUTTON_START_HOOVER "ressources/images/menus/buttons_hoover/start.png"
#define BUTTON_LOAD_GAME_HOOVER "ressources/images/menus/buttons_hoover/load_game.png"
#define BUTTON_OPTIONS_HOOVER "ressources/images/menus/buttons_hoover/options.png"
#define BUTTON_EXIT_HOOVER "ressources/images/menus/buttons_hoover/exit.png"

//fonts
#define CHINYEN_FONT "ressources/fonts/menus/chinyen.otf"

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
