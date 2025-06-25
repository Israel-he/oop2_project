#pragma once

#include "MovingObject.h"
#include "GameObject.h"

class snakeBody : public MovingObject
{
public:
    snakeBody(sf::Texture& texture, sf::Vector2f& position);

    void move(float deltaTime) override;
    void draw(sf::RenderWindow& window) override;

    void setPosition(sf::Vector2f pos);    // פונקציה להצבת מיקום
    void setRotation(float angle);         // (אופציונלי) אם תשתמש בסיבוב
	void setIsMove(bool isMove) { m_isMove = isMove; } // פונקציה להצבת מצב תנועה
    //double dispatch
    virtual void handleCollision(GameObject& gameObject);
    virtual void handleCollision(snake& gameObject);
    virtual void handleCollision(snakeBody& gameObject) {};
    virtual void handleCollision(Food& gameObject) {};
    virtual void handleCollision(Wall& gameObject) {};
    virtual void handleCollision(extraFood& gameObject) {};


private:
	sf::Vector2f m_info; // מיקום של חלק גוף הנחש
	float m_speed;        // מהירות תנועת חלק גוף הנחש
	bool m_isMove = false; // האם החלק בתנועה
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