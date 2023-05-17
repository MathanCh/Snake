#include "board.hpp"
#include "snake.hpp"

#include <iostream>

int main()
{
	float windowXSize = 500;
	float windowYSize = 500;
	sf::RenderWindow window(sf::VideoMode(windowXSize, windowYSize), "Snake");
	
	float thickness = 5;
	
	Borders wall(	Point(thickness, thickness), 
					Point(windowXSize - 2 * thickness, windowYSize - (2 * thickness)), 
					thickness, sf::Color::Blue, sf::Color::Transparent);
	
	Board board(wall, Board::WallMode::KILL);
	
	Snake snake(10, Point(250, 250), 0.25, Snake::MoveDirection::UP, sf::Color::Red);
	
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
        	
        	//std::cout << "increased size" << std::endl;
        }
        
        snake.Move(wall);
        
        window.clear();
        
        board.DrawBoard(window);
        snake.DrawSnake(window);
        
        window.display();
    }
	return 0;
}











