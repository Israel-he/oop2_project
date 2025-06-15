#pragma once

#include <SFML/Graphics.hpp>
#include "snakeBody.h"
#include <vector>

class snake : public MovingObject
{
public:
    snake(sf::Texture& head);

    void move(float deltaTime) override;
    void draw(sf::RenderWindow& window);
    void changeSprite();
    sf::Vector2f getPosition();
    void setSpeed(float speed);
    void addBodyPart(sf::Texture& texture); // תוכל להשתמש בזה להוסיף חוליה
    void setSpacing();
private:
    float m_speed;
    float m_countTime = 0.0f;
    float m_changeTime = 1.f; // זמן בין שינויי ספרייט

    sf::Vector2f m_direction;
    int m_rotation = 0;

    std::vector<snakeBody> m_snakeBody;              // גוף הנחש (ללא הראש)
   // std::vector<sf::Vector2f> m_positionsHistory;    // היסטוריית מיקומים של הראש
    struct SnakeHistoryEntry {
        sf::Vector2f position;
        
    };

    std::vector<SnakeHistoryEntry> m_positionsHistory;

    int m_spacing = 6;      // מרחק צעדים בין כל חוליה
    int m_bodyCount = 2;     // מספר חוליות התחלתיות
};





























//#pragma once
//
//#include <SFML/Graphics.hpp>
//#include "snakeBody.h"
//#include <vector>
//
//class snake : public MovingObject
//{
//public:
//
//	snake(sf::Texture& head);
//	void move(float deltaTime) override;
//	void draw(sf::RenderWindow& window);
//	void changeSprite();
//	sf::Vector2f getPosition();
//	void setSpeed(float speed);
//	void addBodyPart(sf::Texture& texture);
//
//
//private:
//
//	
//	float m_speed;
//	float m_countTime = 0.0f;
//	float m_changeTime = 1.f; // זמן שינוי כיוון
//	sf::Vector2f m_direction;
//	//std::vector<snakeBody> m_body;
//	std::vector<sf::Vector2f> m_bodyParts;
//	
//	int m_rotation = 0; // זווית סיבוב של הראש
//	//sf::Texture m_texture;  
//
//	std::vector<snakeBody> m_snakeBody; //snakeBody
//	 
//
//};


 