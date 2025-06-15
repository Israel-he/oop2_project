#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <string>
class Texture 
{
public:

	Texture();
	void loadFromFile(); // Load texture from file
	sf::Texture& getTexture(std::string& name);
	void draw(sf::RenderWindow& window);
private:

	std::map<std::string, sf::Texture> m_textureMap; // Map to hold textures by name

	std::vector<std::string> textureFiles;
	std::string end = ".png"; // File extension for textures
 };