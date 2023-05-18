#include "segment.hpp"

Segment::Segment(Point pos_, float radius_, sf::Color color_):
Point(pos_), 
m_segment(radius_)
{
	m_segment.setFillColor(color_);
	m_segment.setPosition(this->GetX(), this->GetY());
}

Segment::operator sf::CircleShape() const
{
	return m_segment;
}
