#include "board.hpp"

Board::Board(Borders wall_, WallMode wallMode_):
m_wall(wall_), 
m_wallMode(wallMode_)
{
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

void Board::DrawBoard(sf::RenderWindow& window)
{
	window.draw(m_wall);
}
