#include "board.hpp"
#include "snake.hpp"

#include <iostream>

int main()
{
	float windowXSize = 800;
	float windowYSize = 800;
	
	float thickness = 5;
	
	sf::RenderWindow window(sf::VideoMode(windowXSize + 2 * thickness, windowYSize + 2 * thickness), "Snake");
	
	Borders wall(	Point(thickness, thickness), 
					Point(windowXSize, windowYSize), 
					thickness, sf::Color::Blue, sf::Color::Transparent);
	
	Board board(wall, Board::WallMode::WARP);
	
	float radius = 10;
	float speed = 10;
	
	Point startingPt(	windowXSize/2 + thickness + radius, 
						windowYSize/2 + thickness + radius);
	
	Snake snake(radius, startingPt, speed, Snake::MoveDirection::UP, 
				sf::Color::Green);
	
	sf::Clock clock;
	
	while (window.isOpen())
    {	
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
       	
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			snake.SetDirection(Snake::MoveDirection::LEFT);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			snake.SetDirection(Snake::MoveDirection::RIGHT);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			snake.SetDirection(Snake::MoveDirection::UP);
		}
		else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			snake.SetDirection(Snake::MoveDirection::DOWN);
		}
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::F))
        {
        	snake.IncreaseSize();
        }
        
       	sf::Time elapsed = clock.getElapsedTime();
       	
       	bool deathStatus = snake.GetDeathStatus();
       	
       	if(elapsed.asMilliseconds() > 1000 / snake.GetSpeed() && !deathStatus)
       	{
       		board.GenerateFood(snake.GetRadius());
			snake.Move(board);
			clock.restart();
       	}
       	
        window.clear();
        
        board.DrawBoard(window, snake.GetRadius());
        snake.DrawSnake(window);
        
        window.display();
    }
	return 0;
}











