#include <iostream>
#include <string>

#include <startmenu.h>

using namespace std;

int main()
{
    StartMenu *startMenu;


    //music
    SoundManager soundMenu;
    soundMenu.playMusic("dark_winds", 40, true);

    startMenu = new StartMenu();


}

