#include "ReadFromFile.h"
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <memory>
#include "Wall.h"
#include "Food.h"
#include "snake.h"
ReadFromFile::ReadFromFile(const std::string& filename)
{
    m_photoTex.loadFromFile("photo.png");
    m_grassTex.loadFromFile("grass.png");

	loadFromFile(filename);
}

 
 
void ReadFromFile::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);
    char line;
    int row = 0;
    int col = 0;
    if (!file)
    {
        throw std::runtime_error("Failed to open board file: " + filename);
    }

    while (file.get(line))
    {

        switch (line)
        {
        case ID::WALL:
            m_position = sf::Vector2f(col * ID::WITH_WALL, row * ID::HIGHT_WALL);
            m_walls.push_back(std::make_unique<Wall>(m_photoTex, m_position));
            break;
        case ID::PLAYER:
			m_position = sf::Vector2f(col * 34, row * 54);
            m_snake = std::make_unique<snake>(m_photoTex, m_position);
            break;
        case ID::FOOD:
			m_position = sf::Vector2f(col * 29, row * 28);
            m_foods.push_back(std::make_unique<Food>(m_photoTex, m_position));
            break;
        case '\n':
            col = 0;
            row++;
            break;
        }
		if (line != '\n')  
		{
			col++;
		}
    }
    file.close();
}

//===================extractSnake==================
std::unique_ptr<snake> ReadFromFile::extractSnake()
{
    return std::move(m_snake);
}

//===================getUnmovableObjects==================
std::vector<std::unique_ptr<GameObject>> ReadFromFile::getWalls()
{
    return std::move(m_walls);
}

//===================getFood==================
std::vector<std::unique_ptr<GameObject>> ReadFromFile::getFood()
{
	return std::move(m_foods);
}

//===================getGrassesTexture==================
sf::Texture& ReadFromFile::getGrassTexture()
{
    return m_grassTex;
}

//===================getPhotoTexture==================
sf::Texture& ReadFromFile::getPhotoTexture()
{
	return m_photoTex;
}


 































//const float TILE_SIZE = 50.0f; // גודל של אריח
//
//ReadFromFile::ReadFromFile(sf::Texture& wallTex, sf::Texture& floorTex, sf::Texture& playerTex, sf::Texture& bonusTex, const std::string& filename)
//{
//    loadFromFile(filename, wallTex, floorTex, playerTex, bonusTex);
//}
//
//ReadFromFile::ReadFromFile(const std::string& filename, sf::Texture& playerTex)
//{
//}
//
//void ReadFromFile::loadFromFile(const std::string& filename,
//    sf::Texture& wallTex,
//    sf::Texture& floorTex,
//    sf::Texture& playerTex,
//    sf::Texture& bonusTex)
//{
//    std::ifstream file(filename);
//    std::string line;
//    int row = 0;
//
//    if (!file) {
//        std::cerr << "Failed to open board file: " << filename << std::endl;
//        return;
//    }
//
//    while (std::getline(file, line)) {
//        for (size_t col = 0; col < line.size(); ++col) {
//            sf::Sprite tile;
//
//            switch (line[col]) {
//            case '#':
//                tile.setTexture(wallTex);
//                break;
//            case 'P':
//                tile.setTexture(playerTex);
//                break;
//            case '*':
//                tile.setTexture(bonusTex);
//                break;
//            case ' ':
//            default:
//                tile.setTexture(floorTex);
//                break;
//            }
//
//            tile.setPosition(col * TILE_SIZE, row * TILE_SIZE);
//            m_tiles.push_back(tile);
//        }
//        ++row;
//    }
//}
//
//void ReadFromFile::draw(sf::RenderWindow& window)
//{
//    for (auto& tile : m_tiles)
//        window.draw(tile);
//}


