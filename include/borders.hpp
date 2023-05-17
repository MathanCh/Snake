#ifndef __BORDERS_HPP__
#define __BORDERS_HPP__

#include <SFML/Graphics.hpp>

#include "point.hpp"

class Borders
{
public:
	Borders(Point topLeftPt_, Point bottomRightPt_, float thickness_, 
			sf::Color outlineColor_, sf::Color fillColor_);
	
	operator sf::RectangleShape() const;
	
	Point GetTopLeftPt() const;
	Point GetBottomRightPt() const;
	
	float GetThickness() const;
	
private:
	sf::RectangleShape m_borders;
	float m_thickness;
	Point m_topLeftPt;
	Point m_bottomRightPt;
};

#endif /*__BORDERS_HPP__*/
