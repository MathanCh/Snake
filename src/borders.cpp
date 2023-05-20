#include "borders.hpp"

Borders::Borders(	Point topLeftPt_, Point bottomRightPt_, float thickness_, 
					sf::Color outlineColor_, sf::Color fillColor_):
m_borders(sf::Vector2f(	bottomRightPt_.GetX() - topLeftPt_.GetX(), 
						bottomRightPt_.GetY() - topLeftPt_.GetY())), 
m_thickness(thickness_), 
m_topLeftPt(topLeftPt_), 
m_bottomRightPt(bottomRightPt_)
{
	m_borders.setOutlineColor(outlineColor_);
	m_borders.setFillColor(fillColor_);
	m_borders.setOutlineThickness(m_thickness);
	m_borders.setPosition(m_topLeftPt.GetX(), m_topLeftPt.GetY());
}

Borders::~Borders()
{
}

Borders::operator sf::RectangleShape() const
{
	return m_borders;
}

Point Borders::GetTopLeftPt() const
{
	return m_topLeftPt;
}

Point Borders::GetBottomRightPt() const
{
	return m_bottomRightPt;
}

float Borders::GetThickness() const
{
	return m_thickness;
}

void Borders::setFillColor(sf::Color color)
{
	m_borders.setFillColor(color);
}

void Borders::setBorderColor(sf::Color color)
{
	m_borders.setOutlineColor(color);
}
