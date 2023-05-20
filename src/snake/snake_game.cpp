#include "snake_game.hpp"

#include <iostream>

SnakeGame::SnakeGame():
Game("Snake"), 
m_wallThickness(5), 
m_panelHeight(50), 
m_width(800 + (2 * m_wallThickness)), 
m_height(800 + (2 * m_wallThickness) + m_panelHeight), 
m_radius(10), 
m_speed(20), 
m_window(), 
m_gameBoard(Borders(Point(m_wallThickness, m_wallThickness), 
					Point(	m_width - m_wallThickness, 
							m_height - m_wallThickness - m_panelHeight), 
					m_wallThickness, sf::Color::Blue, sf::Color::Transparent), 
			Panel(Point(0, m_height - m_panelHeight), Point(m_width, m_height), 
						sf::Color::White, sf::Color::Black), 
			SnakeBoard::WARP), 
m_snake(m_radius, 
		Point(	m_width / 2 + m_radius, 
				(m_height - m_panelHeight) / 2 + m_radius), 
		m_speed, 
		Snake::MoveDirection::NONE, sf::Color::Green)
{
}

SnakeGame::~SnakeGame()
{
}

void SnakeGame::Run()
{
	m_window.create(sf::VideoMode(m_width, m_height), "Snake", sf::Style::Titlebar | sf::Style::Close);

	sf::Clock clock;
	
	Snake::MoveDirection newDirection(m_snake.GetDirection());

	bool paused = false;
	bool pStatus = false;

	m_gameBoard.GenerateFood(m_snake.GetRadius());

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

		m_snake.DrawSnake(m_window);
        m_gameBoard.DrawBoard(m_window, m_snake.GetRadius(), paused, deathStatus);
		
        m_window.display();
    }

	m_snake.ResetSnake();

	m_gameBoard.Reset();
}