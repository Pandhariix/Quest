#include "startmenu.h"


StartMenu::StartMenu()
{
    this->start = false;
    this->loadGame = false;
    this->options = false;
    this->exit = false;

    sf::Texture backgroundImage;
    sf::Texture buttonStartImage;
    sf::Texture buttonLoadGameImage;
    sf::Texture buttonOptionsImage;
    sf::Texture buttonExitImage;
    sf::Texture buttonStartImageHoover;
    sf::Texture buttonLoadGameImageHoover;
    sf::Texture buttonOptionsImageHoover;
    sf::Texture buttonExitImageHoover;

    sf::Sprite background;
    sf::Sprite buttonStart;
    sf::Sprite buttonLoadGame;
    sf::Sprite buttonOptions;
    sf::Sprite buttonExit;

    sf::Font titleFont;

    sf::Text titleText;

    this->name = "Quest";
    this->width = 800;
    this->length = 600;

    this->startMenu = new sf::RenderWindow(sf::VideoMode(this->width, this->length), this->name, sf::Style::Titlebar);
    this->startMenu->setFramerateLimit(120);
    this->startMenu->setTitle(this->name);

    //textures
    if(!backgroundImage.loadFromFile(START_SCREEN))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonStartImage.loadFromFile("Images/StartMenu/button_start.png"))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonLoadGameImage.loadFromFile("Images/StartMenu/button_loadGame.png"))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonOptionsImage.loadFromFile("Images/StartMenu/button_options.png"))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonExitImage.loadFromFile("Images/StartMenu/button_exit.png"))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonStartImageHoover.loadFromFile("Images/StartMenu/button_start_hoover.png"))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonLoadGameImageHoover.loadFromFile("Images/StartMenu/button_loadGame_hoover.png"))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonOptionsImageHoover.loadFromFile("Images/StartMenu/button_options_hoover.png"))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonExitImageHoover.loadFromFile("Images/StartMenu/button_exit_hoover.png"))
        std::cerr<<"Unable to load the background image"<<std::endl;

    //sprites
    background.setTexture(backgroundImage);
    buttonStart.setTexture(buttonStartImage);
    buttonLoadGame.setTexture(buttonLoadGameImage);
    buttonOptions.setTexture(buttonOptionsImage);
    buttonExit.setTexture(buttonExitImage);

    buttonStart.setPosition(sf::Vector2f(50, this->startMenu->getSize().y*0.25));
    buttonLoadGame.setPosition(sf::Vector2f(50, this->startMenu->getSize().y*0.4));
    buttonOptions.setPosition(sf::Vector2f(50, this->startMenu->getSize().y*0.55));
    buttonExit.setPosition(sf::Vector2f(50, this->startMenu->getSize().y*0.7));


    //fonts
    if(!titleFont.loadFromFile(CHINYEN_FONT))
        std::cerr<<"Unable to load the title font"<<std::endl;

    //text
    titleText.setFont(titleFont);
    titleText.setString("Quest");
    titleText.setCharacterSize(42);
    titleText.setColor(sf::Color::White);
    titleText.setStyle(sf::Text::Bold);
    titleText.setPosition(sf::Vector2f((this->startMenu->getSize().x/2)-75, 0));

    //draw on the window
    this->startMenu->draw(background);
    this->startMenu->draw(titleText);
    this->startMenu->draw(buttonStart);
    this->startMenu->draw(buttonLoadGame);
    this->startMenu->draw(buttonOptions);
    this->startMenu->draw(buttonExit);


    //display the menu
    this->startMenu->display();

    //check the events on the window
    while(this->startMenu->isOpen())
    {
        sf::Event event;
        while(this->startMenu->pollEvent(event))
        {
           // if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
             //   buttonStart.setTexture(buttonStartImageHoover);
                //this->startMenu->display();

            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                if(sf::Mouse::getPosition(*startMenu).x >= buttonStart.getPosition().x &&
                   sf::Mouse::getPosition(*startMenu).x <= buttonStart.getPosition().x+buttonStartImage.getSize().x &&
                   sf::Mouse::getPosition(*startMenu).y >= buttonStart.getPosition().y &&
                   sf::Mouse::getPosition(*startMenu).y <= buttonStart.getPosition().y+buttonStartImage.getSize().y)
                {
                    buttonStart.setTexture(buttonStartImageHoover);
                    buttonLoadGame.setTexture(buttonLoadGameImage);
                    buttonOptions.setTexture(buttonOptionsImage);
                    buttonExit.setTexture(buttonExitImage);

                    this->soundMenu.playSound("click_button", 60, false);
                    this->start = true;
                }
                else if(sf::Mouse::getPosition(*startMenu).x >= buttonLoadGame.getPosition().x &&
                        sf::Mouse::getPosition(*startMenu).x <= buttonLoadGame.getPosition().x+buttonLoadGameImage.getSize().x &&
                        sf::Mouse::getPosition(*startMenu).y >= buttonLoadGame.getPosition().y &&
                        sf::Mouse::getPosition(*startMenu).y <= buttonLoadGame.getPosition().y+buttonLoadGameImage.getSize().y)
                {
                    buttonStart.setTexture(buttonStartImage);
                    buttonLoadGame.setTexture(buttonLoadGameImageHoover);
                    buttonOptions.setTexture(buttonOptionsImage);
                    buttonExit.setTexture(buttonExitImage);

                    this->soundMenu.playSound("click_button", 60, false);
                    this->loadGame = true;
                }
                else if(sf::Mouse::getPosition(*startMenu).x >= buttonOptions.getPosition().x &&
                        sf::Mouse::getPosition(*startMenu).x <= buttonOptions.getPosition().x+buttonOptionsImage.getSize().x &&
                        sf::Mouse::getPosition(*startMenu).y >= buttonOptions.getPosition().y &&
                        sf::Mouse::getPosition(*startMenu).y <= buttonOptions.getPosition().y+buttonOptionsImage.getSize().y)
                {
                    buttonStart.setTexture(buttonStartImage);
                    buttonLoadGame.setTexture(buttonLoadGameImage);
                    buttonOptions.setTexture(buttonOptionsImageHoover);
                    buttonExit.setTexture(buttonExitImage);

                    this->soundMenu.playSound("click_button", 60, false);
                    this->options = true;
                }
                else if(sf::Mouse::getPosition(*startMenu).x >= buttonExit.getPosition().x &&
                        sf::Mouse::getPosition(*startMenu).x <= buttonExit.getPosition().x+buttonExitImage.getSize().x &&
                        sf::Mouse::getPosition(*startMenu).y >= buttonExit.getPosition().y &&
                        sf::Mouse::getPosition(*startMenu).y <= buttonExit.getPosition().y+buttonExitImage.getSize().y)
                {
                    buttonStart.setTexture(buttonStartImage);
                    buttonLoadGame.setTexture(buttonLoadGameImage);
                    buttonOptions.setTexture(buttonOptionsImage);
                    buttonExit.setTexture(buttonExitImageHoover);

                    this->soundMenu.playSound("click_button", 60, false);

                    //stop the music and exit
                    this->exit = true;
                }
            }

            if(event.type == sf::Event::Closed)
                //this->exit = true;
                this->startMenu->close();
        }
        this->startMenu->clear();

        this->startMenu->draw(background);
        this->startMenu->draw(titleText);
        this->startMenu->draw(buttonStart);
        this->startMenu->draw(buttonLoadGame);
        this->startMenu->draw(buttonOptions);
        this->startMenu->draw(buttonExit);

        this->startMenu->display();

        //if start is clicked
        if(this->start)
        {
            this->startMenu->close();
        }

        //if the load game button is clicked
        if(this->loadGame)
        {
            LoadGameMenu *loadGameMenu;
            loadGameMenu = new LoadGameMenu(this->startMenu);

            if(loadGameMenu->getBack())
            {
                delete loadGameMenu;
                this->soundMenu.playSound("click_button", 60, false);
                this->loadGame = false;
            }
            else if(loadGameMenu->getExit())
            {
                delete loadGameMenu;
                this->loadGame = false;
                this->soundMenu.playSound("click_button", 60, false);
                this->exit = true;
            }
        }

        // if the option button is clicked
        if(this->options)
        {
            OptionsMenu *optionsMenu;
            optionsMenu = new OptionsMenu(this->startMenu);

            if(optionsMenu->getBack() || optionsMenu->getSaveAndBackToMenu())
            {
                delete optionsMenu;
                this->soundMenu.playSound("click_button", 60, false);
                this->options = false;
            }
            else if(optionsMenu->getExit())
            {
                delete optionsMenu;
                this->options = false;
                this->soundMenu.playSound("click_button", 60, false);
                this->exit = true;
            }
        }

        // if the exit button is clicked
        if(this->exit)
        {
            this->startMenu->close();
        }
    }
}

bool StartMenu::getStart()
{
    return this->start;
}
bool StartMenu::getLoadGame()
{
    return this->loadGame;
}
bool StartMenu::getOptions()
{
    return this->options;
}
bool StartMenu::getExit()
{
    return this->exit;
}

StartMenu::~StartMenu()
{

}

