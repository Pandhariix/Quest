#ifndef LOADGAMEMENU_H
#define LOADGAMEMENU_H

#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
#include <soundmanager.h>

//images
#define START_SCREEN "ressources/images/menus/StartScreen.jpg"

//buttons
#define BUTTON_BACK "ressources/images/menus/buttons/back.png"
#define BUTTON_EXIT "ressources/images/menus/buttons/exit.png"

#define BUTTON_BACK_HOOVER "ressources/images/menus/buttons_hoover/back.png"
#define BUTTON_EXIT_HOOVER "ressources/images/menus/buttons_hoover/exit.png"

//fonts
#define CHINYEN_FONT "ressources/fonts/menus/chinyen.otf"

class LoadGameMenu
{

private:

    int width;
    int length;
    std::string name;

    sf::RenderWindow *loadGameMenu;
    std::vector <std::string> nameSaves;
    std::vector <sf::Text> displayNameSaves;
    std::vector <sf::RectangleShape> displaySave;

    bool back;
    bool exit;

public:

    LoadGameMenu(sf::RenderWindow *loadGameMenu);

    bool getSaveAndBackToMenu();
    bool getBack();
    bool getExit();

    ~LoadGameMenu();

};

#endif // LOADGAMEMENU_H
