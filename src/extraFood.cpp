#include "extraFood.h"
#include "snake.h"
#include "io.h"
extraFood::extraFood(sf::Texture& texture, sf::Vector2f& position)
    : GameObject(texture, position)
{
    m_sprite.setTextureRect(sf::IntRect(435, 215, ID::WITH_E_FOOD, ID::HIGHT_E_FOOD));
}

void extraFood::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
}

//===================isEaten===================
bool extraFood::getIsEaten() const
{
    return m_isEaten;
}

//===================update===================
void extraFood::update(float deltaTime)
{
    m_lifetime += deltaTime;
    if (m_lifetime >= DISAPPEAR_TIME) {
        m_overTime = true;  // Or m_isEaten = true; if you prefer
    }
}

//===================handleCollision===================
void extraFood::handleCollision(GameObject& gameObject)
{
    gameObject.handleCollision(*this);
}

//SNAKE
//void Food::handleCollision(snake& gameObject)
//{
//	if (m_sprite.getGlobalBounds().intersects(gameObject.getSprite().getGlobalBounds()))
//	{
//		gameObject.handleCollision(*this);
//		m_isEaten = true; // סימון שהאוכל נאכל
//	}
//
//	return;
//}


void extraFood::handleCollision(snake& gameObject)
{
    sf::FloatRect foodRect = m_sprite.getGlobalBounds();
    sf::FloatRect headRect = gameObject.getSprite().getGlobalBounds();

    sf::FloatRect intersection;
    if (foodRect.intersects(headRect, intersection))
    {
        float headArea = headRect.width * headRect.height;
        float intersectionArea = intersection.width * intersection.height;

        // Check if at least 30% of the head overlaps with the food
        if (intersectionArea >= 0.2f * headArea)
        {
            gameObject.handleCollision(*this);
            m_isIsEatenExtra = true; // סימון שהאוכל נאכל
			m_isEaten = true; // סימון שהאוכל נאכל
        }
    }
}