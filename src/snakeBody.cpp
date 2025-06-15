
#include "snakeBody.h"

snakeBody::snakeBody(sf::Texture& texture)
    : MovingObject(texture), m_speed(10.0f)
{
    m_sprite.setTextureRect(sf::IntRect(330, 140, 22, 38));
    m_sprite.setOrigin(11.0f, 19.0f);
    m_sprite.setPosition(100.0f, 70.0f);
   
}

void snakeBody::move(float deltaTime)
{
    // אפשר לממש כאן תנועה נוספת אם תחליט להוסיף תכונות מתקדמות
}

void snakeBody::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

void snakeBody::setPosition(sf::Vector2f pos)
{
    m_sprite.setPosition(pos);
}

void snakeBody::setRotation(float angle)
{
    m_sprite.setRotation(angle);
}













//#include "snakeBody.h"
//
//snakeBody::snakeBody(sf::Texture& texture)
//	:MovingObject(texture), m_speed(10.0f)
//{
//	//m_sprite.setTexture(texture);
//
//	m_sprite.setPosition(100.0f, 70.0f);
//	 
//	m_sprite.setTextureRect(sf::IntRect(330 , 140, 22, 38)); // Set the texture rectangle for the sprite
//	m_sprite.setOrigin(11.0f, 19.0f); // Set the origin for rotation and scaling
//}
//
////==============move==========
//void snakeBody::move(float deltaTime)
//{
//	if (m_direction.y == -1)
//		m_sprite.setRotation(0.f); // Up
//	else if (m_direction.y == 1)
//		m_sprite.setRotation(180.f); // Down
//	else if (m_direction.x == -1)
//		m_sprite.setRotation(90.f); // Left
//	else if (m_direction.x == 1)
//		m_sprite.setRotation(270.f); // Right
//	m_sprite.setPosition(m_position);
//	m_sprite.move(m_info);
//}
//
//
////==============draw==========
//void snakeBody::draw(sf::RenderWindow& window)
//{
//// Ensure the sprite is at the correct position before drawing
//	window.draw(m_sprite); 
//}
//
////==============getPosition==========
//void snakeBody::getInfo(sf::Vector2f& info)
//{
//	m_info = info;
//}
//
