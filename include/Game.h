#include <SFML/Graphics.hpp>  // For graphics, windows, and drawing
#include <SFML/Window.hpp>    // For window management and input
#include <SFML/System.hpp>    // For system utilities (threads, time, etc.)
#include <SFML/Audio.hpp>     // For audio playback and recording
#include <SFML/Network.hpp>   // For networking features
#include <random>
#pragma once
//#include "snake.h"
//#include "Board.h"
 
#include "ReadFromFile.h"
class Game
{
public:

	Game();
	Game(float playerSpeed);
	void createWindow();
	void getTexGrassTexture(sf::Texture& texture);
	void getTexPhotoTexture(sf::Texture& texture);
	
	void loadTextures();
	void run();
	void handleEndChkCollisions(GameObject& gameObject);
	sf::Vector2f getValidFoodPosition();
	void update();
	void render();
	void draw();
	bool isOpen() const { return m_window.isOpen(); }

private:

	//game window
	sf::RenderWindow m_window;
	sf::View m_view;
	int m_high;                
	int m_width;
	
	


	ReadFromFile m_readFromFile;

	//Objects
	std::unique_ptr<snake> m_snake; 
	std::vector<std::unique_ptr<GameObject>> m_walls; // קירות או אובייקטים שאינם נעים
	std::vector<std::unique_ptr<GameObject>> m_foods; // מזון
	//Board m_board;  
	sf::Clock m_clock; 
	float m_deltaTime = 0.0f;
	sf::Sprite m_startButton;  
	sf::Sprite m_grassSprite;
	 sf::Texture m_PhotoSprite;
	sf::Vector2f m_posOfNewFood; // מיקום מזון חדש
};