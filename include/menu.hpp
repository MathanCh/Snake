#ifndef __MENU_HPP__
#define __MENU_HPP__

#include <string>
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <map>

#include "game.hpp"
#include "button.hpp"

class Menu
{
public:
    Menu(std::string name_);

    void Start();

    void AddOption(std::shared_ptr<Game> gameToAdd_);

private:
    sf::RenderWindow m_menuWindow;
    std::string m_name;
    float m_width;
    float m_height;
    sf::Font m_font;
    std::vector<std::shared_ptr<Button>> m_options;
    std::map<std::shared_ptr<Button>, std::shared_ptr<Game>> m_games;
};

#endif /*__MENU_HPP__*/