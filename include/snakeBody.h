#pragma once

#include "MovingObject.h"
#include "GameObject.h"

class snakeBody : public MovingObject
{
public:
    snakeBody(sf::Texture& texture);

    void move(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;

    void setPosition(sf::Vector2f pos);    // פונקציה להצבת מיקום
    void setRotation(float angle);         // (אופציונלי) אם תשתמש בסיבוב

private:
	sf::Vector2f m_info; // מיקום של חלק גוף הנחש
	float m_speed;        // מהירות תנועת חלק גוף הנחש
};
































//#pragma once
//#include "MovingObject.h"
//#include "GameObject.h"
////#include <SFML/Graphics.hpp>
//
//
//class snakeBody : public MovingObject
//{
//
//public:
//	snakeBody(sf::Texture& texture);
//  
//	void move(float deltaTime) override;
//	 
//	void draw(sf::RenderWindow& window) override;
// 
//	void getInfo(sf::Vector2f& info);
//	
//private:
//	sf::Vector2f m_info; // Position of the snake body part
//	float m_speed;
//};