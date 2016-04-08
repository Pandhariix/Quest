#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
#include <soundmanager.h>

//images
#define START_SCREEN "ressources/images/menus/StartScreen.jpg"

//buttons
#define BUTTON_SAVE_AND_BACK_TO_TITLE "ressources/images/menus/buttons/save_and_back_to_title.png"
#define BUTTON_BACK "ressources/images/menus/buttons/back.png"
#define BUTTON_EXIT "ressources/images/menus/buttons/exit.png"

#define BUTTON_SAVE_AND_BACK_TO_TITLE_HOOVER "ressources/images/menus/buttons_hoover/save_and_back_to_title.png"
#define BUTTON_BACK_HOOVER "ressources/images/menus/buttons_hoover/back.png"
#define BUTTON_EXIT_HOOVER "ressources/images/menus/buttons_hoover/exit.png"

//fonts
#define CHINYEN_FONT "ressources/fonts/menus/chinyen.otf"

class OptionsMenu
{

private:

    int width;
    int length;
    std::string name;

    sf::RenderWindow *optionsMenu;

    bool saveAndBackToMenu;
    bool back;
    bool exit;

public:

    OptionsMenu(sf::RenderWindow *optionsMenu);

    bool getSaveAndBackToMenu();
    bool getBack();
    bool getExit();

    ~OptionsMenu();
};

#endif // OPTIONSMENU_H
