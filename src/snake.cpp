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
	m_snake.push_back(m_pos);
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
	
	Point nextPos;
	
	switch(m_moveDirection)
	{
		case LEFT:
			nextPos.setXY(m_pos.GetX() - amount, m_pos.GetY());
			
			CheckSelf(nextPos);
			CheckWall(board, nextPos);
			CheckFood(board, nextPos);
			
			m_snake.push_back(Point(nextPos));
			break;
		
		case RIGHT:
			nextPos.setXY(m_pos.GetX() + amount, m_pos.GetY());
			
			CheckSelf(nextPos);
			CheckWall(board, nextPos);
			CheckFood(board, nextPos);
			
			m_snake.push_back(Point(nextPos));
			break;
		
		case UP:
			nextPos.setXY(m_pos.GetX(), m_pos.GetY() - amount);
			
			CheckSelf(nextPos);
			CheckWall(board, nextPos);
			CheckFood(board, nextPos);
			
			m_snake.push_back(Point(nextPos));
			break;
		
		case DOWN:
			nextPos.setXY(m_pos.GetX(), m_pos.GetY() + amount);
			
			CheckSelf(nextPos);
			CheckWall(board, nextPos);
			CheckFood(board, nextPos);
			
			m_snake.push_back(Point(nextPos));
			break;
	}
	
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
	sf::CircleShape segment(m_radius);
	segment.setFillColor(m_color);
	
	for(auto iter = m_snake.begin(); m_snake.end() != iter; ++iter)
	{
		segment.setPosition((*iter).GetX(), (*iter).GetY());
		window.draw(segment);
	}
}

void Snake::CheckWall(Board& board, Point& nextPos)
{
	Board::WallMode mode(board.GetWallMode());
	
	Point topLeft(board.GetTopLeft());
	Point bottomRight(board.GetBottomRight());
	
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

void Snake::CheckSelf(Point nextPos)
{
	for(auto iter = m_snake.begin(); m_snake.end() != iter; ++iter)
	{
		if(nextPos == (*iter))
		{
			m_isDead = true;
		}
	}
}

void Snake::CheckFood(Board& board, Point nextPos)
{
	if(nextPos == board.GetFoodPos())
	{
		m_isGrowing = true;
		board.EatFood();
	}
}




















