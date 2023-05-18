#include "snake.hpp"

#include <iostream>

Snake::Snake(	float radius_, Point center_, float speed_, 
			MoveDirection moveDirection_, sf::Color color_):
m_snake(), 
m_size(0), 
m_radius(radius_), 
m_color(color_), 
m_pos(Point(center_.GetX() - m_radius, center_.GetY() - m_radius)), 
m_speed(speed_), 
m_moveDirection(moveDirection_), 
m_isGrowing(false), 
m_isDead(false)
{
	m_snake.push_back(Segment(m_pos, m_radius, m_color));
}

Point Snake::GetPos() const
{
	return m_pos;
}

float Snake::GetXPos() const
{
	return m_pos.GetX();
}
	
float Snake::GetYPos() const
{
	return m_pos.GetY();
}

float Snake::GetRadius() const
{
	return m_radius;
}

float Snake::GetSpeed() const
{
	return m_speed;
}

bool Snake::GetDeathStatus() const
{
	return m_isDead;
}

Snake::MoveDirection Snake::GetDirection() const
{
	return m_moveDirection;
}

void Snake::SetPos(Point newPos)
{
	m_pos = newPos;
}

void Snake::setPos(float x, float y)
{
	m_pos.SetX(x);
	m_pos.SetY(y);
}

void Snake::SetDirection(MoveDirection direction)
{
	m_moveDirection = direction;
}

void Snake::Move(Board& board)
{
	float amount = 2 * m_radius;
	
	Segment nextPos(m_pos, m_radius, m_color);
	
	switch(m_moveDirection)
	{
		case LEFT:
			nextPos.setXY(m_pos.GetX() - amount, m_pos.GetY());
			break;
		
		case RIGHT:
			nextPos.setXY(m_pos.GetX() + amount, m_pos.GetY());
			break;
		
		case UP:
			nextPos.setXY(m_pos.GetX(), m_pos.GetY() - amount);
			break;
		
		case DOWN:
			nextPos.setXY(m_pos.GetX(), m_pos.GetY() + amount);
			break;
	}
	
	CheckSelf(nextPos);
	CheckWall(board, nextPos);
	CheckFood(board, nextPos);
	
	m_snake.push_back(nextPos);
	
	m_pos = nextPos;
	
	if(!m_isGrowing)
	{
		m_snake.erase(m_snake.begin());
	}
	else
	{
		m_isGrowing = false;
	}
}

void Snake::IncreaseSize()
{
	m_isGrowing = true;
}

void Snake::DrawSnake(sf::RenderWindow& window)
{
	for(auto iter = m_snake.begin(); m_snake.end() != iter; ++iter)
	{
		window.draw(*iter);
	}
}

void Snake::CheckWall(Board& board, Segment& nextPos)
{
	Board::WallMode mode(board.GetWallMode());
	
	Point topLeft(board.GetTopLeftPt());
	Point bottomRight(board.GetBottomRightPt());
	
	switch(mode)
	{
		case Board::KILL:
			if(	nextPos.GetX() < topLeft.GetX() || 
				nextPos.GetX() > bottomRight.GetX() || 
				nextPos.GetY() < topLeft.GetY() || 
				nextPos.GetY() > bottomRight.GetY())
			{
				m_isDead = true;
			}
			break;
		
		case Board::WARP:
			if(nextPos.GetX() < topLeft.GetX())
			{
				nextPos.SetX(bottomRight.GetX() - 2 * m_radius);
			}
			else if(nextPos.GetX() > bottomRight.GetX())
			{
				nextPos.SetX(topLeft.GetX());
			}
			else if(nextPos.GetY() < topLeft.GetY())
			{
				nextPos.SetY(bottomRight.GetY() - 2 * m_radius);
			}
			else if(nextPos.GetY() > bottomRight.GetY())
			{
				nextPos.SetY(topLeft.GetY());
			}
			break;
	}
}

void Snake::CheckSelf(Segment nextPos)
{
	for(auto iter = m_snake.begin(); m_snake.end() != iter; ++iter)
	{
		if(nextPos == (*iter))
		{
			m_isDead = true;
		}
	}
}

void Snake::CheckFood(Board& board, Segment nextPos)
{
	if(nextPos == board.GetFoodPos())
	{
		m_isGrowing = true;
		board.EatFood();
	}
}




















