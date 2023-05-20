#include "point.hpp"

Point::Point(float x_, float y_):
m_x(x_), 
m_y(y_)
{
}

Point::~Point()
{
}

void Point::SetX(float x_)
{
	m_x = x_;
}

void Point::SetY(float y_)
{
	m_y = y_;
}

void Point::setXY(float x_, float y_)
{
	m_x = x_;
	m_y = y_;
}

float Point::GetX() const
{
	return m_x;
}

float Point::GetY() const
{
	return m_y;
}

bool Point::operator==(Point& other_) const
{
	return ((m_x == other_.m_x) && (m_y == other_.m_y));
}

std::ostream& operator<<(std::ostream& os_, Point pt)
{
	return os_ << "(" << pt.GetX() << ", " << pt.GetY() << ")";
}
