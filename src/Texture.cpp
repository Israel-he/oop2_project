#include "Texture.h"

Texture::Texture()
{
	loadFromFile();
}

void Texture::loadFromFile()
{
	 
	textureFiles.push_back("face1");
 
	textureFiles.push_back("grass");

	for (int i=0;i< textureFiles.size();i++)
	{
		sf::Texture texture;

		if (!texture.loadFromFile(textureFiles[i] + end))
			throw std::runtime_error("Failed to load texture: " + textureFiles[i]);

		m_textureMap[textureFiles[i]] = std::move(texture);
	}
}
//==========getTexture==========
sf::Texture& Texture::getTexture(std::string& name)
{
	for (auto& texture : m_textureMap) {
		if (texture.first == name) 
		{
			return texture.second; 
		}
	}
	//throw std::runtime_error("Texture not found: " + name); // Throw an error if not found
}

//==========draw==========
void Texture::draw(sf::RenderWindow& window)
{
	for (auto& texture : m_textureMap) {
		sf::Sprite sprite(texture.second);  
		window.draw(sprite); 
	}
}


