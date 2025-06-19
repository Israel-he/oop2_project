#include "MovingObject.h"


MovingObject::MovingObject(sf::Texture& texture, sf::Vector2f& position)
	:GameObject(texture, position), m_speed(0.0f), m_direction(0.0f, 0.0f)
{
}

