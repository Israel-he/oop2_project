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
void Food::handleCollision(snake& gameObject)
{
	if (m_sprite.getGlobalBounds().intersects(gameObject.getSprite().getGlobalBounds()))
	{
		gameObject.handleCollision(*this);
		m_isEaten = true; // סימון שהאוכל נאכל
	}

	return;
}
