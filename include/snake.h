#pragma once

#include <SFML/Graphics.hpp>
#include "snakeBody.h"
#include <vector>

class snake : public MovingObject
{
public:
    snake(sf::Texture& head, sf::Vector2f& position);

    void move(float deltaTime) override;
    void draw(sf::RenderWindow& window);
    void changeSprite();
    sf::Vector2f getPosition();
    void setSpeed(float speed);
    void addBodyPart(sf::Texture& texture); // תוכל להשתמש בזה להוסיף חוליה
    void setSpacing();
	snakeBody& getSnakeBody(const int index);
    int getSnakeBodySize() const;
	std::vector<snakeBody>& getSnakeBodyVector(); // מחזיר את הווקטור של גוף הנחש
    //double dispatch
    virtual void handleCollision(GameObject& gameObject);
    virtual void handleCollision(snake& gameObject) {};
    virtual void handleCollision(snakeBody& gameObject);
    virtual void handleCollision(Food& gameObject);
    virtual void handleCollision(Wall& gameObject) {};
    virtual void handleCollision(extraFood& gameObject);

private:
    float m_speed;
    float m_countTime = 0.0f;
    float m_changeTime = 0.09f; // זמן בין שינויי ספרייט

    sf::Vector2f m_direction;
    int m_rotation = 0;
    sf::Vector2f posBody;//for no reason
    std::vector<snakeBody> m_snakeBody;              // גוף הנחש (ללא הראש)
   // std::vector<sf::Vector2f> m_positionsHistory;    // היסטוריית מיקומים של הראש
    struct SnakeHistoryEntry {
        sf::Vector2f position;
        
    };

    std::vector<SnakeHistoryEntry> m_positionsHistory;

    int m_spacing = 6;      // מרחק צעדים בין כל חוליה
    int m_bodyCount = 2;     // מספר חוליות התחלתיות
};


 