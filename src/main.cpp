#pragma once
 
#include <iostream> 
#include "Menu.h"
//int main()
//{
//	try
//	{
//		Game game; // Create a Game object
//		game.run(); // Start the game loop
//	}
//	catch (const std::exception& e)
//	{
//		std::cerr << "Error: " << e.what() << std::endl; // Catch and display any exceptions
//		return EXIT_FAILURE; // Exit with failure status
//	}
//}


int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    Menu menu(window);
    menu.run();

    return 0;
}
