#include "panel.hpp"

#include <string>

Panel::Panel(   Point topLeftPt_, Point bottomRightPt_,  
                sf::Color fillColor_, sf::Color textColor_):
m_panel(sf::Vector2f(bottomRightPt_.GetX(), 
        bottomRightPt_.GetY() - topLeftPt_.GetY())), 
m_topLeft(topLeftPt_), 
m_bottomRight(bottomRightPt_), 
m_textColor(textColor_), 
m_font(), 
m_score(0)
{
    m_panel.setFillColor(fillColor_);
    m_panel.setPosition(topLeftPt_.GetX(), topLeftPt_.GetY());

	m_font.loadFromFile("Arial.ttf");
}

Panel::operator sf::RectangleShape() const
{
    return m_panel;
}

size_t Panel::GetScore() const
{
    return m_score;
}

void Panel::SetScore(size_t score_)
{
    m_score = score_;
}

void Panel::Draw(sf::RenderWindow& window, bool paused, bool dead)
{
    window.draw(m_panel);

    sf::Text score("Score: " + std::to_string(m_score), m_font);

    score.setFillColor(m_textColor);
    score.setPosition(m_topLeft.GetX() + 5, m_topLeft.GetY() + 5);
    score.setCharacterSize(20);

    window.draw(score);

    sf::Text gameStatus;

    gameStatus.setFont(m_font);
    gameStatus.setFillColor(m_textColor);
    gameStatus.setPosition(m_bottomRight.GetX() / 2 - 90, m_topLeft.GetY() + 5);
    gameStatus.setCharacterSize(20);

    if(dead)
    {
        gameStatus.setString("Game Over!");
    }
    else if(paused)
    {
        gameStatus.setString("Game Paused!");
    }
    else
    {
        gameStatus.setString("");
    }

    window.draw(gameStatus);
}