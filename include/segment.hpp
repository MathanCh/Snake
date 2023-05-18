#ifndef __SEGMENT_HPP__
#define __SEGMENT_HPP__

#include <SFML/Graphics.hpp>

#include "point.hpp"

class Segment: public Point
{
public:
	Segment(Point pos_, float radius_, sf::Color color_);
	
	operator sf::CircleShape() const;
	
private:
	sf::CircleShape m_segment;
};

#endif /*__SEGMENT_HPP__*/
