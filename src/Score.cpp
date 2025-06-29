#include "Score.h"

Score::Score()
{
	if (!m_font.loadFromFile("C:/Windows/Fonts/arial.ttf")) {
		throw std::runtime_error("Failed to load font from ");
	}
	m_text.setFont(m_font);
	m_text.setCharacterSize(24);
	m_text.setFillColor(sf::Color::Blue);
	reset();
}

//========== addPoints ==========

void Score::addPoints(int points)
{
	score += points;
	m_text.setString("Score: " + std::to_string(score) + " Level: " + std::to_string(m_level));
}
//========== getScore ==========
int Score::getScore() const
{
	return score;
}

void Score::setLevel(int level)
{
	m_level = level;
	m_text.setString("Score: " + std::to_string(score) + " Level: " + std::to_string(m_level));
}

//========== reset ==========
void Score::reset()
{
	score = 0;
	//m_text.setString("Score: " + std::to_string(score) + " Level: " + std::to_string(level));
}

//========== setPosition ==========
void Score::setPosition(const sf::Vector2f& position)
{
	m_text.setPosition(position);
}

//========== draw ==========
void Score::draw(sf::RenderWindow& window)
{
	window.draw(m_text);
}

