#include "Button.h"

Button::Button(const sf::Font& font, const std::string& text, unsigned int charSize, sf::Vector2f position) {
    m_text.setFont(font);
    m_text.setString(text);
    m_text.setCharacterSize(charSize);
    m_text.setFillColor(sf::Color::White);
    m_text.setPosition(position);

	 
}

//============== draw ==========
void Button::draw(sf::RenderWindow& window) const 
{
    window.draw(m_text);
}

//============== isMouseOver ==========
bool Button::isMouseOver(const sf::RenderWindow& window, sf::Vector2i mousePos) const {
    return m_text.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos));
}

//============== setFillColor ==========
void Button::setFillColor(const sf::Color& color) {
    m_text.setFillColor(color);
}