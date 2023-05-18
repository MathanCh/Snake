#include "game.hpp"

SnakeGame::SnakeGame(	float width_, float height_, std::string name_, 
						Board gameBoard_, 
						Snake snake_):
m_window(sf::VideoMode(width_, height_), name_), 
m_gameBoard(gameBoard_), 
m_snake(snake_)
{
}

void SnakeGame::RunGame()
{
	sf::Clock clock;
	
	Snake::MoveDirection newDirection(Snake::MoveDirection::UP);

	bool paused = false;
	bool pStatus = false;

	while (m_window.isOpen())
    {	
        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                m_window.close();
            }
        }
       	
       	Snake::MoveDirection currDir = m_snake.GetDirection();

		if(	sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && 
			currDir != Snake::MoveDirection::RIGHT && !paused)
		{
			newDirection = Snake::MoveDirection::LEFT;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && 
				currDir != Snake::MoveDirection::LEFT && !paused)
		{
			newDirection = Snake::MoveDirection::RIGHT;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && 
				currDir != Snake::MoveDirection::DOWN && !paused)
		{
			newDirection = Snake::MoveDirection::UP;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && 
				currDir != Snake::MoveDirection::UP && !paused)
		{
			newDirection = Snake::MoveDirection::DOWN;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::P) && !pStatus)
		{
			if(!paused)
			{
				paused = true;
			}
			else
			{
				paused = false;
			}

			pStatus = true;
		}
		else if(!sf::Keyboard::isKeyPressed(sf::Keyboard::P))
		{
			pStatus = false;
		}
        
       	sf::Time elapsed = clock.getElapsedTime();
       	
       	bool deathStatus = m_snake.GetDeathStatus();
       	
       	if(	elapsed.asMilliseconds() > 1000 / m_snake.GetSpeed() && !deathStatus && !paused)
       	{
			m_snake.SetDirection(newDirection);
			m_gameBoard.GenerateFood(m_snake.GetRadius());
			m_snake.Move(m_gameBoard);

			clock.restart();
       	}
       	
        m_window.clear();

        m_gameBoard.DrawBoard(m_window, m_snake.GetRadius(), paused, deathStatus);
		m_snake.DrawSnake(m_window);
		
        m_window.display();
    }
}
