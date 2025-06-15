#include "GameObject.h"


GameObject::GameObject(sf::Texture& texture)
	:m_position(110.0f, 110.0f), m_texture(texture)
{
	m_sprite.setTexture(texture); 
	m_sprite.setPosition(m_position); 
	
}

//==========setPosition==========
void GameObject::setPosition(sf::Vector2f position)
{
}
