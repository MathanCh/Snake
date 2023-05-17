#ifndef __SNAKE_HPP__
#define __SNAKE_HPP__

#include <SFML/Graphics.hpp>
#include <cmath>
#include <vector>
#include <memory>

#include "board.hpp"

class Snake
{
public:
	enum MoveDirection
	{
		LEFT = 0, 
		RIGHT = 1, 
		UP = 2, 
		DOWN = 3
	};
	
	Snake(	float radius_, Point center_, float speed_, 
			MoveDirection moveDirection_, sf::Color color_);
	
	Point GetPos() const;
	float GetXPos() const;
	float GetYPos() const;
	float GetRadius() const;
	float GetSpeed() const;
	bool GetDeathStatus() const;
	
	void SetPos(Point newPos);
	void setPos(float x, float y);
	void SetDirection(MoveDirection direction);
	
	void Move(Board& board);
	
	void IncreaseSize();
	
	void DrawSnake(sf::RenderWindow& window);
	
private:
	void CheckWall(Board& board, Point& nextPos);
	void CheckSelf(Point nextPos);
	void CheckFood(Board& board, Point nextPos);
	
	std::vector<Point> m_snake;
	float m_size;
	float m_radius;
	sf::Color m_color;
	Point m_pos;
	float m_speed;
	MoveDirection m_moveDirection;
	bool m_isGrowing;
	bool m_isDead;
};

#endif /*__SNAKE_HPP__*/












