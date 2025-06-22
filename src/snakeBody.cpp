#include "snakeBody.h"
#include "io.h"
#include "snake.h"
snakeBody::snakeBody(sf::Texture& texture, sf::Vector2f& position)
    : MovingObject(texture, position), m_speed(10.0f)
{
    m_sprite.setTextureRect(sf::IntRect(330, 140, ID::WITH_BODY,ID::HIGHT_BODY));
    m_sprite.setOrigin(11.0f, 19.0f);
    m_sprite.setPosition(100.0f, 70.0f);
   
}

void snakeBody::move(float deltaTime)
{
    
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

//========== handleCollision ==========
void snakeBody::handleCollision(GameObject& gameObject)
{
}

//snake
void snakeBody::handleCollision(snake& gameObject)
{
     //Get the bounding rectangles
    sf::FloatRect bodyRect = m_sprite.getGlobalBounds();
    sf::FloatRect headRect = gameObject.getSprite().getGlobalBounds();

     //Calculate intersection rectangle
    sf::FloatRect intersection;
    if (bodyRect.intersects(headRect, intersection))
    {
        // Calculate areas
        float headArea = headRect.width * headRect.height;
        float intersectionArea = intersection.width * intersection.height;

        // Check if more than 50% of the head overlaps with the body
        if (intersectionArea >= 0.4f * headArea && m_isMove)
        {
            gameObject.setIsDead(true); // Mark snake as dead
        }
    }
}


 