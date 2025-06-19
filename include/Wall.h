#pragma once
#include <SFML/Graphics.hpp> 
#include "GameObject.h"
class Wall : public GameObject
{
public:
	Wall(sf::Texture& texture, sf::Vector2f& position);

	void draw(sf::RenderWindow& window) override;

    //double dispatch
    virtual void handleCollision(GameObject& gameObject);
    virtual void handleCollision(snake& gameObject);
    virtual void handleCollision(snakeBody& gameObject) {};
    virtual void handleCollision(Food& gameObject) {};
    virtual void handleCollision(Wall& gameObject) {};
};