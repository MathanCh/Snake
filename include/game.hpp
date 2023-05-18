#ifndef __GAME_HPP__
#define __GAEM_HPP__

#include <string>

#include "board.hpp"
#include "snake.hpp"

class SnakeGame
{
public:
	SnakeGame(	float width, float height, std::string name, Board gameBoard_, 
				Snake snake_);
	
	void RunGame();
private:
	sf::RenderWindow m_window;
	Board m_gameBoard;
	Snake m_snake;
	bool m_paused;
};

#endif /*__GAME_HPP__*/
