#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "borders.hpp"

class Board
{
public:
	enum WallMode
	{
		WARP = 0, 
		KILL = 1
	};
	
	Board(Borders wall_, WallMode wallMode_);
	
	WallMode GetWallMode() const;
	Point GetTopLeft() const;
	Point GetBottomRight() const;
	Point GetFoodPos() const;
	
	void EatFood();
	
	void GenerateFood(float radius);
	void DrawBoard(sf::RenderWindow& window, float radius);
	
private:
	static size_t RandomNumber(size_t min, size_t max);
	
	Borders m_wall;
	WallMode m_wallMode;
	bool m_isThereFood;
	Point m_food;
};
#endif /*__BOARD_HPP__*/
