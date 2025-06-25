#pragma once
#include <SFML/Graphics.hpp> 
class snake;
class snakeBody;
class Food;
class Wall;
class extraFood;


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
	virtual bool getDeleteFoodOverTime()const { return false; };
	virtual bool getIsEatenExtra()const { return false; };
	virtual bool getIsEaten()const;
	virtual void setIsDead(bool isDead) { m_isDead = isDead; }
	virtual bool getIsDead() const { return m_isDead; }
	virtual void update(float deltaTime) {};
	//double dispatch
	bool checkCollision(const GameObject& other) const;

	virtual void handleCollision(GameObject& gameObject) = 0;
	virtual void handleCollision(snake& gameObject) = 0;
	virtual void handleCollision(snakeBody& gameObject) = 0;
	virtual void handleCollision(Food& gameObject) = 0;
	virtual void handleCollision(Wall& gameObject) = 0;
	virtual void handleCollision(extraFood& gameObject) = 0;

protected:

	sf::Sprite m_sprite;      // Sprite for rendering the game object 
	sf::Texture m_texture;    // Texture for the sprite
	sf::Vector2f m_position; // Position of the game object

	bool m_isDead = false;  
	bool m_overTime = false;//for the extra food, if it is eaten over time
};