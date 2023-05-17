#ifndef __SNAKE_HPP__
#define __SNAKE_HPP__

#include <SFML/Graphics.hpp>
#include <cmath>
#include <set>
#include <memory>

#include "borders.hpp"

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
	
	void SetPos(Point newPos);
	void setPos(float x, float y);
	void SetDirection(MoveDirection direction);
	
	void Move(Borders wall);
	void UpdatePos();
	
	void IncreaseSize();
	
	void DrawSnake(sf::RenderWindow& window);
	
private:
	void CheckWall(Borders wall);
	void MoveHead(float amount);
	
	sf::CircleShape m_head;
	std::set<std::shared_ptr<Point>> m_tail;
	float m_size;
	float m_radius;
	sf::Color m_color;
	Point m_center;
	float m_speed;
	MoveDirection m_moveDirection;
};

#endif /*__SNAKE_HPP__*/












