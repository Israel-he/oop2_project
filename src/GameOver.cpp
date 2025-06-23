#include "GameOver.h"

GameOver::GameOver(std::string& text)
	:GameWindow(text)
{
}

//========== draw ==========
void GameOver::draw()
{
	m_window.clear(sf::Color::Black);
	m_window.draw(m_text);
	m_window.display();
}

//========== createText ==========
void GameOver::createText()
{
	GameWindow::setText();

	m_textPosition = sf::Vector2f(m_window.getSize().x / 2.f - m_text.getLocalBounds().width / 2.f -30.f,
		m_window.getSize().y / 2.f - m_text.getLocalBounds().height / 2.f - 30.f);
	m_text.setFillColor(sf::Color::Red);
	m_text.setCharacterSize(48);
	m_text.setPosition(m_textPosition);
}
