#ifndef __SNAKE_HPP__
#define __SNAKE_HPP__

#include <cmath>
#include <vector>
#include <memory>

#include "snake_board.hpp"
#include "segment.hpp"

class Snake
{
public:
	enum MoveDirection
	{
		NONE = 0, 
		LEFT = 1, 
		RIGHT = 2, 
		UP = 3, 
		DOWN = 4
	};
	
	Snake(	float radius_, Point center_, float speed_, 
			MoveDirection moveDirection_, sf::Color color_);
	
	Point GetPos() const;
	float GetXPos() const;
	float GetYPos() const;
	float GetRadius() const;
	float GetSpeed() const;
	bool GetDeathStatus() const;
	MoveDirection GetDirection() const;
	
	void SetPos(Point newPos);
	void setPos(float x, float y);
	void SetDirection(MoveDirection direction);
	
	void Move(SnakeBoard& board);
	
	void IncreaseSize();
	
	void DrawSnake(sf::RenderWindow& window);
	
	void ResetSnake();

private:
	void CheckWall(SnakeBoard& board, Segment& nextPos);
	void CheckSelf(Segment nextPos);
	void CheckFood(SnakeBoard& board, Segment nextPos);
	
	std::vector<Segment> m_snake;
	float m_radius;
	sf::Color m_color;
	Point m_pos;
	Point m_startPos;
	float m_speed;
	MoveDirection m_moveDirection;
	bool m_isGrowing;
	bool m_isDead;
};

#endif /*__SNAKE_HPP__*/












