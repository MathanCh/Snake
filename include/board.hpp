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
	
	void DrawBoard(sf::RenderWindow& window);
	
	static float RandomFloat(float min, float max);
	
private:
	Borders m_wall;
	WallMode m_wallMode;
};
#endif /*__BOARD_HPP__*/
