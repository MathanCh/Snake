#include "game.hpp"
#include "segment.hpp"
#include <iostream>

int main()
{
	float windowXSize = 800;
	float windowYSize = 800;
	
	float thickness = 5;
	
	float panelHeight = 50;
	
	Borders wall(	Point(thickness, thickness), 
					Point(windowXSize, windowYSize), 
					thickness, sf::Color::Blue, sf::Color::Transparent);
	
	Board board(wall, Board::WallMode::WARP);
	
	float radius = 10;
	float speed = 20;
	
	Point startingPt(	windowXSize/2 + thickness + radius, 
						windowYSize/2 + thickness + radius);
	
	Snake snake(radius, startingPt, speed, Snake::MoveDirection::UP, 
				sf::Color::Green);
	
	SnakeGame game(	windowXSize + 2 * thickness, 
					windowYSize + 2 * thickness + panelHeight, "snake", board, 
					snake);
	
	game.RunGame();
	
	return 0;
}











