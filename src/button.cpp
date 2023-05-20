#include "button.hpp"

Button::Button( Borders border_, std::string text_, sf::Color textColor_, 
                sf::Color borderColor_, sf::Color hoverColor_, 
                sf::Color fillColor_, sf::Color pressColor_):
Borders(border_), 
m_text(text_), 
m_font(), 
m_textColor(textColor_), 
m_borderColor(borderColor_), 
m_hoverColor(hoverColor_), 
m_fillColor(fillColor_), 
m_pressColor(pressColor_), 
m_isMouseOver(false)
{
    m_font.loadFromFile("Arial.ttf");
}

void Button::Draw(sf::RenderWindow& window)
{
    window.draw(*this);

    sf::Text text(m_text, m_font);
    text.setCharacterSize(20);
    text.setFillColor(m_textColor);

    Point topLeft(GetTopLeftPt());

    text.setPosition(topLeft.GetX() + 20, topLeft.GetY() + 2);

    window.draw(text);
}

void Button::Hover(bool isMouseOver_)
{
    if(isMouseOver_)
    {
        setBorderColor(m_hoverColor);
    }
    else
    {
        setBorderColor(m_borderColor);
    }

    m_isMouseOver = isMouseOver_;
}

bool Button::Press(bool isPressed)
{
    if(m_isMouseOver && isPressed)
    {
        setFillColor(m_pressColor);
        
        return true;
    }
    else
    {
        setFillColor(m_fillColor);

        return false;
    }
}