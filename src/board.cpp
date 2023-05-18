#include <cstdlib>
#include <ctime>

#include "board.hpp"

//#include <iostream>

Board::Board(Borders wall_, Panel panel_, WallMode wallMode_):
Borders(wall_), 
m_panel(panel_), 
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

Point Board::GetFoodPos() const
{
	return m_food;
}

void Board::EatFood()
{
	m_isThereFood = false;

	m_panel.SetScore(m_panel.GetScore() + 1);
}

void Board::GenerateFood(float radius)
{
	float diameter = 2 * radius;
	
	Point bottomRight = this->GetBottomRightPt();
	size_t numOfXPts = bottomRight.GetX() / diameter - 1;
	size_t numOfYPts = bottomRight.GetY() / diameter - 1;
	
	if(!m_isThereFood)
	{
		m_food.setXY(	RandomNumber(0, numOfXPts) * diameter + this->GetThickness(), 
						RandomNumber(0, numOfYPts) * diameter + this->GetThickness());
		
		m_isThereFood = true;
	}
}

void Board::DrawBoard(	sf::RenderWindow& window, float radius, 
						bool paused, bool dead)
{
	window.draw(*this);
	
	if(m_isThereFood)
	{
		sf::CircleShape food(radius);
		food.setFillColor(sf::Color::Red);
		food.setPosition(m_food.GetX(), m_food.GetY());
		
		window.draw(food);
	}

	m_panel.Draw(window, paused, dead);
}

size_t Board::RandomNumber(size_t min, size_t max)
{
	return ((rand() % (max - (min - 1))) + min);
}















