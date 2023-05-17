#include "snake.hpp"

Snake::Snake(	float radius_, Point center_, float speed_, 
			MoveDirection moveDirection_, sf::Color color_):
m_head(radius_), 
m_tail(), 
m_size(0), 
m_radius(radius_), 
m_color(color_), 
m_center(center_), 
m_speed(speed_), 
m_moveDirection(moveDirection_)
{
	m_head.setFillColor(color_);
	
	UpdatePos();
}

Point Snake::GetPos() const
{
	return m_center;
}

float Snake::GetXPos() const
{
	return m_center.GetX();
}
	
float Snake::GetYPos() const
{
	return m_center.GetY();
}

float Snake::GetRadius() const
{
	return m_radius;
}

void Snake::SetPos(Point newPos)
{
	m_center = newPos;
	
	UpdatePos();
}

void Snake::setPos(float x, float y)
{
	m_center.SetX(x);
	m_center.SetY(y);
	
	UpdatePos();
}

void Snake::SetDirection(MoveDirection direction)
{
	m_moveDirection = direction;
}

void Snake::Move(Borders wall)
{
	//Point topLeft = wall.GetTopLeftPt();
	//Point bottomRight = wall.GetBottomRightPt();
	
	MoveHead(m_speed);
	
	UpdatePos();
}

void Snake::UpdatePos()
{
	//std::shared_ptr<point>();
	
	m_head.setPosition(m_center.GetX() - m_radius, m_center.GetY() - m_radius);
}

void Snake::IncreaseSize()
{
	m_tail.insert(std::shared_ptr<Point>(new Point(m_center)));
	
	MoveHead(m_speed);
}

void Snake::DrawSnake(sf::RenderWindow& window)
{
	sf::CircleShape segment(m_radius);
	segment.setFillColor(m_color);
	
	for(auto iter = m_tail.begin(); m_tail.end() != iter; ++iter)
	{
		segment.setPosition((*iter)->GetX() - m_radius, (*iter)->GetY() - m_radius);
		window.draw(segment);
	}
	
	window.draw(m_head);
}

void Snake::MoveHead(float amount)
{
	switch(m_moveDirection)
	{
		case LEFT:
			m_center.SetX(m_center.GetX() - amount);
			m_center.SetY(m_center.GetY());
			break;
		
		case RIGHT:
			m_center.SetX(m_center.GetX() + amount);
			m_center.SetY(m_center.GetY());
			break;
		
		case UP:
			m_center.SetX(m_center.GetX());
			m_center.SetY(m_center.GetY() - amount);
			break;
		
		case DOWN:
			m_center.SetX(m_center.GetX());
			m_center.SetY(m_center.GetY() + amount);
			break;
	}
}








