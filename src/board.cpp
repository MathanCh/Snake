#include <cstdlib>
#include <ctime>

#include "board.hpp"

#include <iostream>

Board::Board(Borders wall_, WallMode wallMode_):
m_wall(wall_), 
m_wallMode(wallMode_), 
m_isThereFood(false), 
m_food()
{
	srand(time(NULL));
}

Board::WallMode Board::GetWallMode() const
{
	return m_wallMode;
}

Point Board::GetTopLeft() const
{
	return m_wall.GetTopLeftPt();
}

Point Board::GetBottomRight() const
{
	return m_wall.GetBottomRightPt();
}

Point Board::GetFoodPos() const
{
	return m_food;
}

void Board::EatFood()
{
	m_isThereFood = false;
	//std::cout << "eat! " << m_isThereFood << std::endl;
}

void Board::GenerateFood(float radius)
{
	float diameter = 2 * radius;
	
	Point bottomRight = m_wall.GetBottomRightPt();
	size_t numOfXPts = bottomRight.GetX() / diameter - 1;
	size_t numOfYPts = bottomRight.GetY() / diameter - 1;
	
	//std::cout << "generate! " << m_isThereFood << std::endl;
	
	if(!m_isThereFood)
	{
		m_food.setXY(	RandomNumber(0, numOfXPts) * diameter + m_wall.GetThickness(), 
						RandomNumber(0, numOfYPts) * diameter + m_wall.GetThickness());
		
		//std::cout << m_food << std::endl;
		
		m_isThereFood = true;
	}
}

void Board::DrawBoard(sf::RenderWindow& window, float radius)
{
	window.draw(m_wall);
	
	if(m_isThereFood)
	{
		sf::CircleShape food(radius);
		food.setFillColor(sf::Color::Red);
		food.setPosition(m_food.GetX(), m_food.GetY());
		
		window.draw(food);
	}
}

size_t Board::RandomNumber(size_t min, size_t max)
{
	return ((rand() % (max - (min - 1))) + min);
}















