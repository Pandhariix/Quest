#include "optionsmenu.h"

OptionsMenu::OptionsMenu(sf::RenderWindow *optionsMenu)
{
    this->saveAndBackToMenu = false;
    this->back = false;
    this->exit = false;

    sf::Texture backgroundImage;
    sf::Texture buttonSaveAndBackToMenuImage;
    sf::Texture buttonBackImage;
    sf::Texture buttonExitImage;
    sf::Texture buttonSaveAndBackToMenuImageHoover;
    sf::Texture buttonBackImageHoover;
    sf::Texture buttonExitImageHoover;

    sf::Sprite background;
    sf::Sprite buttonSaveAndBackToMenu;
    sf::Sprite buttonBack;
    sf::Sprite buttonExit;

    sf::Font titleFont;

    sf::Text titleText;

    this->name = "Options";
    this->width = 800;
    this->length = 600;

    this->optionsMenu = optionsMenu;
    this->optionsMenu->clear();
    this->optionsMenu->setFramerateLimit(120);
    this->optionsMenu->setTitle(this->name);

    //textures
    if(!backgroundImage.loadFromFile(START_SCREEN))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonSaveAndBackToMenuImage.loadFromFile(BUTTON_SAVE_AND_BACK_TO_TITLE))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonBackImage.loadFromFile(BUTTON_BACK))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonExitImage.loadFromFile(BUTTON_EXIT))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonSaveAndBackToMenuImageHoover.loadFromFile(BUTTON_SAVE_AND_BACK_TO_TITLE_HOOVER))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonBackImageHoover.loadFromFile(BUTTON_BACK_HOOVER))
        std::cerr<<"Unable to load the background image"<<std::endl;
    if(!buttonExitImageHoover.loadFromFile(BUTTON_EXIT_HOOVER))
        std::cerr<<"Unable to load the background image"<<std::endl;

    //sprites
    background.setTexture(backgroundImage);
    buttonSaveAndBackToMenu.setTexture(buttonSaveAndBackToMenuImage);
    buttonBack.setTexture(buttonBackImage);
    buttonExit.setTexture(buttonExitImage);

    buttonSaveAndBackToMenu.setPosition(sf::Vector2f(this->optionsMenu->getSize().x*0.05, 550));
    buttonBack.setPosition(sf::Vector2f(this->optionsMenu->getSize().x*0.45, 550));
    buttonExit.setPosition(sf::Vector2f(this->optionsMenu->getSize().x*0.7, 550));


    //fonts
    if(!titleFont.loadFromFile(CHINYEN_FONT))
        std::cerr<<"Unable to load the title font"<<std::endl;

    //text
    titleText.setFont(titleFont);
    titleText.setString("Quest");
    titleText.setCharacterSize(42);
    titleText.setColor(sf::Color::White);
    titleText.setStyle(sf::Text::Bold);
    titleText.setPosition(sf::Vector2f((this->optionsMenu->getSize().x/2)-75, 0));

    //draw on the window
    this->optionsMenu->draw(background);
    this->optionsMenu->draw(titleText);
    this->optionsMenu->draw(buttonSaveAndBackToMenu);
    this->optionsMenu->draw(buttonBack);
    this->optionsMenu->draw(buttonExit);


    //display the menu
    this->optionsMenu->display();

    //check the events on the window
    while(this->optionsMenu->isOpen())
    {
        sf::Event event;
        while(this->optionsMenu->pollEvent(event))
        {
           // if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
             //   buttonStart.setTexture(buttonStartImageHoover);
                //this->startMenu->display();

            if(event.type == sf::Event::MouseButtonReleased)
            {
                if(sf::Mouse::getPosition(*optionsMenu).x >= buttonSaveAndBackToMenu.getPosition().x &&
                   sf::Mouse::getPosition(*optionsMenu).x <= buttonSaveAndBackToMenu.getPosition().x+buttonSaveAndBackToMenuImage.getSize().x &&
                   sf::Mouse::getPosition(*optionsMenu).y >= buttonSaveAndBackToMenu.getPosition().y &&
                   sf::Mouse::getPosition(*optionsMenu).y <= buttonSaveAndBackToMenu.getPosition().y+buttonSaveAndBackToMenuImage.getSize().y)
                {
                    buttonSaveAndBackToMenu.setTexture(buttonSaveAndBackToMenuImageHoover);
                    buttonBack.setTexture(buttonBackImage);
                    buttonExit.setTexture(buttonExitImage);

                    this->saveAndBackToMenu = true;
                }
                else if(sf::Mouse::getPosition(*optionsMenu).x >= buttonBack.getPosition().x &&
                        sf::Mouse::getPosition(*optionsMenu).x <= buttonBack.getPosition().x+buttonBackImage.getSize().x &&
                        sf::Mouse::getPosition(*optionsMenu).y >= buttonBack.getPosition().y &&
                        sf::Mouse::getPosition(*optionsMenu).y <= buttonBack.getPosition().y+buttonBackImage.getSize().y)
                {
                    buttonSaveAndBackToMenu.setTexture(buttonSaveAndBackToMenuImage);
                    buttonBack.setTexture(buttonBackImageHoover);
                    buttonExit.setTexture(buttonExitImage);

                    this->back = true;
                }
                else if(sf::Mouse::getPosition(*optionsMenu).x >= buttonExit.getPosition().x &&
                        sf::Mouse::getPosition(*optionsMenu).x <= buttonExit.getPosition().x+buttonExitImage.getSize().x &&
                        sf::Mouse::getPosition(*optionsMenu).y >= buttonExit.getPosition().y &&
                        sf::Mouse::getPosition(*optionsMenu).y <= buttonExit.getPosition().y+buttonExitImage.getSize().y)
                {
                    buttonSaveAndBackToMenu.setTexture(buttonSaveAndBackToMenuImage);
                    buttonBack.setTexture(buttonBackImage);
                    buttonExit.setTexture(buttonExitImageHoover);

                    this->exit = true;
                }
            }

            if(event.type == sf::Event::Closed)
                //this->exit = true;
                this->optionsMenu->close();
        }
        this->optionsMenu->clear();

        this->optionsMenu->draw(background);
        this->optionsMenu->draw(titleText);
        this->optionsMenu->draw(buttonSaveAndBackToMenu);
        this->optionsMenu->draw(buttonBack);
        this->optionsMenu->draw(buttonExit);

        this->optionsMenu->display();

        // if the option menu is required
        if(this->back)
        {
            this->optionsMenu->clear();
            break;
        }

        if(this->saveAndBackToMenu)
        {
            this->optionsMenu->clear();
            break;
        }

        if(this->exit)
        {
            this->optionsMenu->clear();
            break;
        }
    }
}

bool OptionsMenu::getBack()
{
    return this->back;
}

bool OptionsMenu::getSaveAndBackToMenu()
{
    return this->saveAndBackToMenu;
}

bool OptionsMenu::getExit()
{
    return this->exit;
}

OptionsMenu::~OptionsMenu()
{

}

