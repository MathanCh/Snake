#ifndef __BUTTON_HPP__
#define __BUTTON_HPP__

#include <string>

#include "borders.hpp"

class Button: public Borders
{
public:
    Button( Borders border_, std::string text_, sf::Color textColor_, 
            sf::Color borderColor_, sf::Color hoverColor_, 
            sf::Color fillColor_, sf::Color pressColor_);
    void Draw(sf::RenderWindow& window);

    void Hover(bool isMouseOver_);

    bool Press(bool isPressed);

private:
    std::string m_text;
    sf::Font m_font;
    sf::Color m_textColor;
    sf::Color m_borderColor;
    sf::Color m_hoverColor;
    sf::Color m_fillColor;
    sf::Color m_pressColor;
    bool m_isMouseOver;
};

#endif /*__BUTTON_HPP__*/