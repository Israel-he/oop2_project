#pragma once
#include <SFML/Graphics.hpp> 
class snake;
class snakeBody;
class Food;
class Wall;

class GameObject {
public:
	GameObject(sf::Texture& texture, sf::Vector2f& position);
	virtual ~GameObject() = default;
	virtual void draw(sf::RenderWindow& window) = 0;

	virtual void setPosition(sf::Vector2f position);
	sf::Vector2f getPosition() const;

	sf::FloatRect getGlobalBounds() const
	{
		return m_sprite.getGlobalBounds();
	}
	sf::Sprite& getSprite();
	virtual bool getIsEaten()const;
	virtual void setIsDead(bool isDead) { m_isDead = isDead; }
	virtual bool getIsDead() const { return m_isDead; }

	//double dispatch
	bool checkCollision(const GameObject& other) const;

	virtual void handleCollision(GameObject& gameObject) = 0;
	virtual void handleCollision(snake& gameObject) = 0;
	virtual void handleCollision(snakeBody& gameObject) = 0;
	virtual void handleCollision(Food& gameObject) = 0;
	virtual void handleCollision(Wall& gameObject) = 0;


protected:

	sf::Sprite m_sprite;      // Sprite for rendering the game object 
	sf::Texture m_texture;    // Texture for the sprite
	sf::Vector2f m_position; // Position of the game object

	bool m_isDead = false;  
};