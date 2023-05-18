#ifndef __PANEL_HPP__
#define __PANEL_HPP__

#include <SFML/Graphics.hpp>

#include "point.hpp"

class Panel
{
public:
    Panel(  Point topLeftPt_, Point bottomRightPt_,  
            sf::Color fillColor_, sf::Color textColor_);

    operator sf::RectangleShape() const;

    size_t GetScore() const;
    void SetScore(size_t score_);

    void Draw(sf::RenderWindow& window, bool paused, bool dead);

private:
    sf::RectangleShape m_panel;
    Point m_topLeft;
    Point m_bottomRight;
    sf::Color m_textColor;
    sf::Font m_font;
    size_t m_score;
};

#endif /*__PANEL_HPP__*/