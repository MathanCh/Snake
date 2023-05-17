#include "board.hpp"

Board::Board(Borders wall_, WallMode wallMode_):
m_wall(wall_), 
m_wallMode(wallMode_)
{
}

void Board::DrawBoard(sf::RenderWindow& window)
{
	window.draw(m_wall);
}
