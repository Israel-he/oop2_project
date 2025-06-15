#pragma once
#include <SFML/Graphics.hpp> 

class GameObject {
public:
	GameObject(sf::Texture& texture);

	virtual void draw(sf::RenderWindow& window) = 0;

	virtual void setPosition(sf::Vector2f position);

    sf::Vector2f getPosition()  const
	{
		return m_sprite.getPosition();
	}
protected:

	sf::Vector2f m_position; // Position of the game object
	sf::Sprite m_sprite;      // Sprite for rendering the game object 
	sf::Texture m_texture;    // Texture for the sprite
};