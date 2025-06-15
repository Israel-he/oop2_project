#include <SFML/Graphics.hpp>  // For graphics, windows, and drawing
#include <SFML/Window.hpp>    // For window management and input
#include <SFML/System.hpp>    // For system utilities (threads, time, etc.)
#include <SFML/Audio.hpp>     // For audio playback and recording
#include <SFML/Network.hpp>   // For networking features

#include "Texture.h"
#include "snake.h"
#include "Board.h"
#include "io.h"

class Game
{
public:

	Game();
	Game(float playerSpeed);
	void createStartWindow();
	void createWindow();
	void loadTextures();
	void run();
	void update();
	void render();

private:

	sf::RenderWindow m_startWindow;
	sf::RenderWindow m_window;
	int m_high;                
	int m_width;
	Texture m_texture;
	snake m_snake; 
	Board m_board;  
	sf::Clock m_clock; 
	float m_deltaTime = 0.0f;
	sf::Sprite m_startButton;  
	
};