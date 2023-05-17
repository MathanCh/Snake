#include "borders.hpp"

Borders::Borders(	Point topLeftPt_, Point bottomRightPt_, float thickness_, 
					sf::Color outlineColor_, sf::Color fillColor_):
m_borders(sf::Vector2f(bottomRightPt_.GetX(), bottomRightPt_.GetY())), 
m_thickness(thickness_), 
m_topLeftPt(topLeftPt_), 
m_bottomRightPt(Point(bottomRightPt_.GetX() + m_thickness, bottomRightPt_.GetY() + m_thickness))
{
	m_borders.setOutlineColor(outlineColor_);
	m_borders.setFillColor(fillColor_);
	m_borders.setOutlineThickness(m_thickness);
	m_borders.setPosition(m_topLeftPt.GetX(), m_topLeftPt.GetY());
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
