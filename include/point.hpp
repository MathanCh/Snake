#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <iostream>

class Point
{
public:
	Point(float x_ = 0, float y_ = 0);
	
	void SetX(float x_);
	void SetY(float y_);
	
	float GetX() const;
	float GetY() const;
	
private:
	float m_x;
	float m_y;
};

std::ostream& operator<<(std::ostream& os_, Point pt);

#endif /*__POINT_HPP__*/
