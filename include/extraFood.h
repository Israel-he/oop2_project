#pragma once
#include "GameObject.h"

class extraFood : public GameObject
{
public:
	extraFood(sf::Texture& texture, sf::Vector2f& position);
	void update(float deltaTime);
	void draw(sf::RenderWindow& window) override;
	bool getIsEaten() const;

	bool getDeleteFoodOverTime()const { return m_overTime; } // Indicates if the extra food is eaten over time
	bool getIsEatenExtra()const { return m_isIsEatenExtra; } // Indicates if the extra food is eaten
	//double dispatch
	virtual void handleCollision(GameObject& gameObject);
	virtual void handleCollision(snake& gameObject);
	virtual void handleCollision(snakeBody& gameObject) {};
	virtual void handleCollision(Food& gameObject) {};
	virtual void handleCollision(Wall& gameObject) {};
	virtual void handleCollision(extraFood& gameObject) {};

private:
	bool m_isEaten = false;
	float m_lifetime = 0.0f; // Time since spawned
	  float DISAPPEAR_TIME = 3.f;
	  bool m_isIsEatenExtra = false; // Indicates if the extra food is eaten
	 // Indicates if the food is eaten over time
};