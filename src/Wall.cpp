#include "Wall.h"
#include "io.h"
#include "snake.h"

Wall::Wall(sf::Texture& texture, sf::Vector2f& position)
	:GameObject(texture, position)
{
	m_sprite.setTextureRect(sf::IntRect(310, 290, ID::WITH_WALL, ID::HIGHT_WALL));
}

//========== draw ==========
void Wall::draw(sf::RenderWindow& window)
{
	window.draw(m_sprite);
}


//========== handleCollision ==========
void Wall::handleCollision(GameObject& gameObject)
{
		gameObject.handleCollision(*this);
}

//SNAKE
void Wall::handleCollision(snake& gameObject)
{
	if (m_sprite.getGlobalBounds().intersects(gameObject.getSprite().getGlobalBounds()))
	{
		gameObject.setIsDead(true); // סימון שהנחש מת
	}

	return;
}
 
