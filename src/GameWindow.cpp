#include "GameWindow.h"

GameWindow::GameWindow(std::string& text)
	:m_txt(text),m_width(800), m_height(600)
{
}
 
//========== createWindow ==========
void GameWindow::createWindow()
{
	m_window.create(sf::VideoMode(m_width, m_height), "Snake", sf::Style::Close | sf::Style::Resize);
	m_window.setFramerateLimit(60);
}

//========== createWindow ==========
bool GameWindow::isOpen()  
{
	return m_window.isOpen();
}

//========== destroyWindow ==========
void GameWindow::setText()
{
	if (!m_font.loadFromFile("arial.ttf")) // ודא שהנתיב לקובץ הפונט נכון
	{
		throw std::runtime_error("Failed to load font");
	}
	m_text.setFont(m_font);
	m_text.setString(m_txt);	 
}

 
