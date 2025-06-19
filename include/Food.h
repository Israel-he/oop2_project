#pragma once
#include "GameObject.h"

class Food : public GameObject
{
public:
	Food(sf::Texture& texture, sf::Vector2f& position);

	void draw(sf::RenderWindow& window) override;
	bool getIsEaten() const;

	//double dispatch
	virtual void handleCollision(GameObject& gameObject);
	virtual void handleCollision(snake& gameObject);
	virtual void handleCollision(snakeBody& gameObject) {};
	virtual void handleCollision(Food& gameObject) {};
	virtual void handleCollision(Wall& gameObject) {};

private:
	bool m_isEaten = false;
};