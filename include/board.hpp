#ifndef __BOARD_HPP__
#define __BOARD_HPP__

#include "borders.hpp"
#include "panel.hpp"

class Board: public Borders
{
public:
	enum WallMode
	{
		WARP = 0, 
		KILL = 1
	};
	
	Board(Borders wall_, Panel panel_, WallMode wallMode_);
	
	WallMode GetWallMode() const;
	Point GetFoodPos() const;
	
	void EatFood();
	
	void GenerateFood(float radius);
	void DrawBoard(	sf::RenderWindow& window, float radius, 
					bool paused, bool dead);
	
private:
	static size_t RandomNumber(size_t min, size_t max);

	Panel m_panel;
	WallMode m_wallMode;
	bool m_isThereFood;
	Point m_food;
};
#endif /*__BOARD_HPP__*/
