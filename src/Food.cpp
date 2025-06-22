#include "Food.h"
#include "snake.h"
#include "io.h"
Food::Food(sf::Texture& texture, sf::Vector2f& position)
	: GameObject(texture, position)
{
	m_sprite.setTextureRect(sf::IntRect(392, 215,ID::WITH_FOOD , ID::HIGHT_FOOD));
}

void Food::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}

//===================isEaten===================
bool Food::getIsEaten() const
{
	return m_isEaten; 
} 

//===================handleCollision===================
void Food::handleCollision(GameObject& gameObject)
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


void Food::handleCollision(snake& gameObject)
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
            m_isEaten = true; // סימון שהאוכל נאכל
        }
    }
}
