#pragma once
#include <SFML/Graphics.hpp>
#include <string>

class Button {
public:
    Button(const sf::Font& font, const std::string& text, unsigned int charSize, sf::Vector2f position);

    void draw(sf::RenderWindow& window) const;
    bool isMouseOver(const sf::RenderWindow& window, sf::Vector2i mousePos) const;
    void setFillColor(const sf::Color& color);

private:
    sf::Text m_text;
};