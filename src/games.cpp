//#include "game.hpp"
//#include "segment.hpp"

#include "snake_game.hpp"
#include "menu.hpp"

#include <iostream>

int main()
{
	Menu menu("Main Menu");

	std::shared_ptr<Game> snake_game(new SnakeGame());

	menu.AddOption(snake_game);

	menu.Start();
	
	return 0;
}











