#pragma once
#include "GameObject.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "io.h"
#include "Texture.h"
#include <memory>

 
#include "Wall.h"
#include "Food.h"
#include "snake.h"
class ReadFromFile
{
public:
   
    ReadFromFile(const std::string& filename);
    void loadFromFile(const std::string& filename);

	std::unique_ptr<snake> extractSnake();
	std::vector<std::unique_ptr<GameObject>> getWalls();
	std::vector<std::unique_ptr<GameObject>> getFood();
	sf::Texture& getGrassTexture();
	sf::Texture& getPhotoTexture();


private:
	sf::Texture m_photoTex;
	sf::Texture m_grassTex;
	 
    std::unique_ptr<snake> m_snake;
	std::vector<std::unique_ptr <GameObject>> m_walls; // קירות	
	std::vector <std::unique_ptr <GameObject>> m_foods; // מזון
	sf::Vector2f m_position; // מיקום של אובייקט במשחק
     
};