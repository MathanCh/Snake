#include "menu.hpp"

#include <iostream>

Menu::Menu(std::string name_):
m_menuWindow(), 
m_name(name_), 
m_width(400), 
m_height(75), 
m_font(), 
m_games()
{
    m_font.loadFromFile("Arial.ttf");
}

void Menu::Start()
{
    m_menuWindow.create(sf::VideoMode(m_width, m_height), m_name, sf::Style::Titlebar | sf::Style::Close);

    m_menuWindow.setPosition(sf::Vector2i(400, 400));

    while(m_menuWindow.isOpen())
    {
        sf::Event event;
        while (m_menuWindow.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                m_menuWindow.close();
            }

            if(event.type == sf::Event::MouseMoved)
            {
                float x = event.mouseMove.x;
                float y = event.mouseMove.y;

                for(auto iter = m_options.begin(); m_options.end() != iter; ++iter)
                {
                    Point topLeft = (*iter)->GetTopLeftPt();
                    Point bottomRight = (*iter)->GetBottomRightPt();
                    
                    (*iter)->Hover(  x >= topLeft.GetX() && 
                                    x <= bottomRight.GetX() && 
                                    y >= topLeft.GetY() && 
                                    y <= bottomRight.GetY());
                }
            }
            
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                for(auto iter = m_options.begin(); m_options.end() != iter; ++iter)
                {
                    if((*iter)->Press(true))
                    {
                        m_menuWindow.setVisible(false);

                        m_games[*iter]->Run();

                        m_menuWindow.setVisible(true);

                        (*iter)->Press(false);

                        (*iter)->Hover(false);
                    }
                }
            }

            if(event.type == sf::Event::MouseButtonReleased)
            {
                for(auto iter = m_options.begin(); m_options.end() != iter; ++iter)
                {
                    (*iter)->Press(false);
                }
            }
        }

        m_menuWindow.clear();

        sf::Text textToPrint("Select a Game:", m_font);
        textToPrint.setCharacterSize(40);
        textToPrint.setPosition(70, 15);
        m_menuWindow.draw(textToPrint);

        for(auto iter = m_options.begin(); m_options.end() != iter; ++iter)
        {
            (*iter)->Draw(m_menuWindow);
        }

        m_menuWindow.display();
    }
}

void Menu::AddOption(std::shared_ptr<Game> gameToAdd_)
{
    static size_t opetionsCounter = 0;

    std::string gameName = gameToAdd_->GetName();

    float nameLength = gameName.length();

    Borders buttonBorder(   Point(5, 70 + (35 * opetionsCounter)), 
                            Point((nameLength * 20) + 10, 70 + (35 * opetionsCounter) + 30), 1, 
                            sf::Color::White, sf::Color::Transparent);

    std::shared_ptr<Button> newButton(new Button(   buttonBorder, "Snake", 
                                                    sf::Color::White, 
                                                    sf::Color::White, 
                                                    sf::Color::Blue, 
                                                    sf::Color::Transparent, 
                                                    sf::Color::Blue));
    
    m_options.push_back(newButton);

    m_height += 35;

    if((nameLength * 20) + 20 > m_width)
    {
        m_width = (nameLength * 20) + 20;
    }

    m_games[newButton] = gameToAdd_;

    ++opetionsCounter;
}