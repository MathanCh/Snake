#ifndef __BORDERS_HPP__
#define __BORDERS_HPP__

#include <SFML/Graphics.hpp>

#include "point.hpp"

class Borders
{
public:
	Borders(Point topLeftPt_, Point bottomRightPt_, float thickness_, 
			sf::Color outlineColor_, sf::Color fillColor_);
	
	virtual ~Borders();
	
	operator sf::RectangleShape() const;
	
	Point GetTopLeftPt() const;
	Point GetBottomRightPt() const;
	
	float GetThickness() const;
	
	void setFillColor(sf::Color color);
	void setBorderColor(sf::Color color);
	
private:
	sf::RectangleShape m_borders;
	float m_thickness;
	Point m_topLeftPt;
	Point m_bottomRightPt;
};

#endif /*__BORDERS_HPP__*/
