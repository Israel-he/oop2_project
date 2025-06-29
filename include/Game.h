#include <SFML/Graphics.hpp>  // For graphics, windows, and drawing
#include <SFML/Window.hpp>    // For window management and input
#include <SFML/System.hpp>    // For system utilities (threads, time, etc.)
#include <SFML/Audio.hpp>     // For audio playback and recording
#include <SFML/Network.hpp>   // For networking features
#include <random>
#pragma once
#include "GameOver.h"
#include "Score.h"
#include "ReadFromFile.h"
#include "WinWidow.h"

class Game
{
public:

	Game();
	Game(float playerSpeed);
	void createWindow();
	void getTexGrassTexture(sf::Texture& texture);
	void getTexPhotoTexture(sf::Texture& texture);
	void loadLevel();
	void nextLel();
	//void createGameOverWindow();
	void setTextGameOver();
	void loadTextures();
	void updateEfood(float deltaTime);
	void run();
	void handleEndChkCollisions(GameObject& gameObject);
	void snakeIsDead();
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

	//game over window
	std::string m_txtGameOver = "Game Over!!";
	GameOver m_gameOver; // חלון סיום המשחק
 
	ReadFromFile m_readFromFile;
	std::string m_txtWinWidow = "YOU WON!!";
	WinWidow m_winWindow; // חלון ניצחון
	
	std::vector<std::string> m_levels = { "level1.txt", "level2.txt", "level3.txt" };
	size_t m_currentLevel = 0;

	//Score
	Score m_score; // ניהול הניקוד
	//Objects
	std::unique_ptr<snake> m_snake; 
	std::vector<std::unique_ptr<GameObject>> m_walls; // קירות או אובייקטים שאינם נעים
	std::vector<std::unique_ptr<GameObject>> m_foods; // מזון
	float m_playerSpeed = 0.0f; // מהירות הנחש
	//Board m_board;  
	sf::Clock m_clock; 
	float m_deltaTime = 0.0f;
	sf::Sprite m_startButton;  
	sf::Sprite m_grassSprite;
	sf::Texture m_PhotoSprite;                              
	sf::Vector2f m_posOfNewFood; // מיקום מזון חדש
	int m_numOfFood = 0; // מספר המזון שנאכל
};