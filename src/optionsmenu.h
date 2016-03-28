#ifndef OPTIONSMENU_H
#define OPTIONSMENU_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
#include <soundmanager.h>

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
