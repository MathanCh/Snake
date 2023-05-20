#ifndef __POINT_HPP__
#define __POINT_HPP__

#include <iostream>

class Point
{
public:
	Point(float x_ = 0, float y_ = 0);
	
	virtual ~Point();
	
	void SetX(float x_);
	void SetY(float y_);
	void setXY(float x_, float y_);
	
	float GetX() const;
	float GetY() const;
	
	bool operator==(Point& other_) const;
	
private:
	float m_x;
	float m_y;
};

std::ostream& operator<<(std::ostream& os_, Point pt);

#endif /*__POINT_HPP__*/
