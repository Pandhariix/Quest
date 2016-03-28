#ifndef LOADGAMEMENU_H
#define LOADGAMEMENU_H

#include <fstream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>
#include <soundmanager.h>

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
