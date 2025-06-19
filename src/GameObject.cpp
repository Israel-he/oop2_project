#include "GameObject.h"


GameObject::GameObject(sf::Texture& texture, sf::Vector2f& position)
	:m_texture(texture), m_position(position)
{
	m_sprite.setTexture(texture); 
	m_sprite.setPosition(m_position); 
	
}

//==========setPosition==========
void GameObject::setPosition(sf::Vector2f position)
{
	m_position = position;
	m_sprite.setPosition(m_position);
}

//==========getPosition==========
sf::Vector2f GameObject::getPosition() const {
	return m_sprite.getPosition();
}

//==========getSprite==========
sf::Sprite& GameObject::getSprite()
{
	return m_sprite;
}

//==========getIsEaten==========
bool GameObject::getIsEaten() const
{
	return false;
}

//==========checkCollision==========
bool GameObject::checkCollision(const GameObject& other) const
{
	if (&other == this) 
		return false;

	return true;
}
