#include "GameObject.h"

class MovingObject :public GameObject
{
public:

	MovingObject(sf::Texture& texture, sf::Vector2f& position);
	 
	virtual void move(float deltaTime) = 0; // Pure virtual function for moving the object
	 
protected:

	float m_speed; // Speed of the moving object
	sf::Vector2f m_direction; // Direction of movement

	 
};