#include "game.hpp"

SnakeGame::SnakeGame(	float width_, float height_, std::string name_, 
						Board gameBoard_, 
						Snake snake_):
m_window(sf::VideoMode(width_, height_), name_), 
m_gameBoard(gameBoard_), 
m_snake(snake_), 
m_paused(false)
{
}

void SnakeGame::RunGame()
{
	sf::Clock clock;
	
	Snake::MoveDirection newDirection(Snake::MoveDirection::UP);
	
	sf::Font font;
	font.loadFromFile("Arial.ttf");
	
	sf::Text score;
	
	score.setFont(font);
	score.setCharacterSize (20);
	score.setFillColor(sf::Color::White);
	score.setPosition(10, 810);
	
	score.setString("score");
	
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
			currDir != Snake::MoveDirection::RIGHT && !m_paused)
		{
			newDirection = Snake::MoveDirection::LEFT;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && 
				currDir != Snake::MoveDirection::LEFT && !m_paused)
		{
			newDirection = Snake::MoveDirection::RIGHT;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && 
				currDir != Snake::MoveDirection::DOWN && !m_paused)
		{
			newDirection = Snake::MoveDirection::UP;
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && 
				currDir != Snake::MoveDirection::UP && !m_paused)
		{
			newDirection = Snake::MoveDirection::DOWN;
		}
        
       	sf::Time elapsed = clock.getElapsedTime();
       	
       	bool deathStatus = m_snake.GetDeathStatus();
       	
       	if(elapsed.asMilliseconds() > 1000 / m_snake.GetSpeed() && !deathStatus)
       	{
       		m_snake.SetDirection(newDirection);
       		m_gameBoard.GenerateFood(m_snake.GetRadius());
			m_snake.Move(m_gameBoard);
			clock.restart();
       	}
       	
        m_window.clear();
        
        m_gameBoard.DrawBoard(m_window, m_snake.GetRadius());
        m_snake.DrawSnake(m_window);
        m_window.draw(score);
        m_window.display();
    }
}
