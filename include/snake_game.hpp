#ifndef __SNAKE_GAME_HPP__
#define __SNAKE_GAEM_HPP__

#include "game.hpp"
#include "snake_board.hpp"
#include "snake.hpp"

class SnakeGame: public Game
{
public:
	SnakeGame();
	
	virtual ~SnakeGame();

	virtual void Run();

private:
	float m_wallThickness;
	float m_panelHeight;
	float m_width;
	float m_height;
	float m_radius;
	float m_speed;
	
	sf::RenderWindow m_window;
	SnakeBoard m_gameBoard;
	Snake m_snake;
};

#endif /*__SNAKE_GAME_HPP__*/
