#include "Game.h"
#include <string>
 
Game::Game()
	: m_high(600), m_width(800), m_texture(), m_snake(m_texture.getTexture(ID::face1)), m_board(m_texture.getTexture(ID::grass))
	   
{
	m_startButton.setPosition(m_width / 2 - m_startButton.getGlobalBounds().width / 2, m_high / 2 - m_startButton.getGlobalBounds().height / 2);
	//createStartWindow();
	createWindow();
 
	run();
}
//=====================================
Game::Game(float playerSpeed)
	: m_high(600), m_width(800), m_texture(), m_snake(m_texture.getTexture(ID::face1)), m_board(m_texture.getTexture(ID::grass))
{
	// שמור את המהירות או תעביר אותה הלאה
	m_snake.setSpeed(playerSpeed);
	createWindow();
	run();
}

//==========createStartWindow==========
void Game::createStartWindow()
{
	m_startWindow.create(sf::VideoMode(m_width, m_high), "Start Game", sf::Style::Close | sf::Style::Resize); // Create the window with specified dimensions and title
	m_startWindow.setFramerateLimit(60); 
}
 
//==========createWindow==========
void Game::createWindow()
{
	m_window.create(sf::VideoMode(m_width, m_high), "Game", sf::Style::Close | sf::Style::Resize); // Create the window with specified dimensions and title
	m_window.setFramerateLimit(60); 
}

//==========loadTextures==========
void Game::loadTextures()
{
 
}

//==========run==========
void Game::run()
{
	 //m_clock.restart(); // Restart the clock to start measuring time
	 m_deltaTime = m_clock.restart().asSeconds();
	 
	while (m_window.isOpen()|| m_startWindow.isOpen()) // Main game loop
	{
		sf::Event event;
		while (m_window.pollEvent(event)) // Poll for events
		{
			if (event.type == sf::Event::Closed) // Check if the window is closed
			{
				m_window.close(); 
				m_startWindow.close();  
			}
		}
		m_snake.move(m_deltaTime); 
		update();
		render();
	}
}

//==========update==========
void Game::update()
{
}

//==========render==========
void Game::render()
{
	m_window.clear(sf::Color::Black); 
	
	m_board.draw(m_window);  
	m_snake.draw(m_window); 
	
	m_window.display(); 

	m_startWindow.clear(sf::Color::Black);
	m_startWindow.draw(m_startButton);
	m_startWindow.display();
}
