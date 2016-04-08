#include <loadgamemenu.h>

LoadGameMenu::LoadGameMenu(sf::RenderWindow *loadGameMenu)
{
    this->back = false;
    this->exit = false;

    sf::Texture backgroundImage;
    sf::Texture buttonBackImage;
    sf::Texture buttonExitImage;
    sf::Texture buttonBackImageHoover;
    sf::Texture buttonExitImageHoover;

    sf::Sprite background;
    sf::Sprite buttonBack;
    sf::Sprite buttonExit;

    sf::Font titleFont;

    sf::Text titleText;

    this->name = "Load Game";
    this->width = 800;
    this->length = 600;

    this->loadGameMenu = loadGameMenu;
    this->loadGameMenu->clear();
    this->loadGameMenu->setFramerateLimit(120);
    this->loadGameMenu->setTitle(this->name);

    //textures
    if(!backgroundImage.loadFromFile(START_SCREEN))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonBackImage.loadFromFile(BUTTON_BACK))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonExitImage.loadFromFile(BUTTON_EXIT))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonBackImageHoover.loadFromFile(BUTTON_BACK_HOOVER))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonExitImageHoover.loadFromFile(BUTTON_EXIT_HOOVER))
        std::cerr<<"Unable to load the background image"<<std::endl;

    //sprites
    background.setTexture(backgroundImage);
    buttonBack.setTexture(buttonBackImage);
    buttonExit.setTexture(buttonExitImage);

    buttonBack.setPosition(sf::Vector2f(this->loadGameMenu->getSize().x*0.3, 550));
    buttonExit.setPosition(sf::Vector2f(this->loadGameMenu->getSize().x*0.6, 550));


    //fonts
    if(!titleFont.loadFromFile(CHINYEN_FONT))
        std::cerr<<"Unable to load the title font"<<std::endl;

    //text
    titleText.setFont(titleFont);
    titleText.setString("Quest");
    titleText.setCharacterSize(42);
    titleText.setColor(sf::Color::White);
    titleText.setStyle(sf::Text::Bold);
    titleText.setPosition(sf::Vector2f((this->loadGameMenu->getSize().x/2)-75, 0));

    // names of the different save files are stocked in the vector nameSaves
    std::ifstream fichier("Saves/saves.list", std::ios::in);

    if(fichier)
    {
        std::string line;

        while(std::getline(fichier, line))
        {
            this->nameSaves.push_back(line);
        }

        fichier.close();
    }

    //creation of the rectangles representing the saves
    this->displaySave.resize(this->nameSaves.size());
    this->displayNameSaves.resize(this->nameSaves.size());

    for(int i=0;i<this->nameSaves.size();i++)
    {
        this->displaySave[i].setSize(sf::Vector2f(this->nameSaves[i].size()*16, 50)); //modif
        this->displaySave[i].setFillColor(sf::Color(0, 0, 0));
        this->displaySave[i].setOutlineThickness(5);
        this->displaySave[i].setOutlineColor(sf::Color(40,238,53));

        if(i == 0)
            this->displaySave[i].setPosition(sf::Vector2f((this->loadGameMenu->getSize().x-this->nameSaves[i].size()*16)/2, 100));
        else
            this->displaySave[i].setPosition(sf::Vector2f((this->loadGameMenu->getSize().x-this->nameSaves[i].size()*16)/2, this->displaySave[i-1].getPosition().y+50+25));

        this->displayNameSaves[i].setFont(titleFont);
        this->displayNameSaves[i].setString(this->nameSaves[i]);
        this->displayNameSaves[i].setCharacterSize(14);
        this->displayNameSaves[i].setColor(sf::Color::White);
        this->displayNameSaves[i].setStyle(sf::Text::Bold);
        this->displayNameSaves[i].setPosition(sf::Vector2f(this->displaySave[i].getPosition().x+10, this->displaySave[i].getPosition().y+10)); //modif
    }

    //draw on the window
    this->loadGameMenu->draw(background);
    this->loadGameMenu->draw(titleText);
    this->loadGameMenu->draw(buttonBack);
    this->loadGameMenu->draw(buttonExit);

    for(int i=0;i<this->displaySave.size();i++)
    {
        this->loadGameMenu->draw(this->displaySave[i]);
    }
    for(int i=0;i<this->displayNameSaves.size();i++)
    {
        this->loadGameMenu->draw(this->displayNameSaves[i]);
    }

    //display the menu
    this->loadGameMenu->display();

    //check the events on the window
    while(this->loadGameMenu->isOpen())
    {
        sf::Event event;
        while(this->loadGameMenu->pollEvent(event))
        {
           // if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
             //   buttonStart.setTexture(buttonStartImageHoover);
                //this->startMenu->display();

            if(event.type == sf::Event::MouseButtonReleased)
            {
                if(sf::Mouse::getPosition(*loadGameMenu).x >= buttonBack.getPosition().x &&
                        sf::Mouse::getPosition(*loadGameMenu).x <= buttonBack.getPosition().x+buttonBackImage.getSize().x &&
                        sf::Mouse::getPosition(*loadGameMenu).y >= buttonBack.getPosition().y &&
                        sf::Mouse::getPosition(*loadGameMenu).y <= buttonBack.getPosition().y+buttonBackImage.getSize().y)
                {
                    buttonBack.setTexture(buttonBackImageHoover);
                    buttonExit.setTexture(buttonExitImage);

                    this->back = true;
                }
                else if(sf::Mouse::getPosition(*loadGameMenu).x >= buttonExit.getPosition().x &&
                        sf::Mouse::getPosition(*loadGameMenu).x <= buttonExit.getPosition().x+buttonExitImage.getSize().x &&
                        sf::Mouse::getPosition(*loadGameMenu).y >= buttonExit.getPosition().y &&
                        sf::Mouse::getPosition(*loadGameMenu).y <= buttonExit.getPosition().y+buttonExitImage.getSize().y)
                {
                    buttonBack.setTexture(buttonBackImage);
                    buttonExit.setTexture(buttonExitImageHoover);

                    this->exit = true;
                }
            }

            if(event.type == sf::Event::Closed)
                //this->exit = true;
                this->loadGameMenu->close();
        }
        this->loadGameMenu->clear();

        this->loadGameMenu->draw(background);
        this->loadGameMenu->draw(titleText);
        this->loadGameMenu->draw(buttonBack);
        this->loadGameMenu->draw(buttonExit);

        for(int i=0;i<this->displaySave.size();i++)
        {
            this->loadGameMenu->draw(this->displaySave[i]);
        }
        for(int i=0;i<this->displayNameSaves.size();i++)
        {
            this->loadGameMenu->draw(this->displayNameSaves[i]);
        }

        this->loadGameMenu->display();

        // if the option menu is required
        if(this->back)
        {
            this->loadGameMenu->clear();
            break;
        }


        if(this->exit)
        {
            this->loadGameMenu->clear();
            break;
        }
    }
}

bool LoadGameMenu::getBack()
{
    return this->back;
}

bool LoadGameMenu::getExit()
{
    return this->exit;
}

LoadGameMenu::~LoadGameMenu()
{

}

