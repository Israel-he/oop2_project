#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Game.h"

static bool m_gameOverWindowOpen = false; // Global variable to track if the game over window is open

class Menu {
public:

    Menu(sf::RenderWindow& window);
    void draw();
    void handleEvent(const sf::Event& event, bool& startGame, float& playerSpeed);
    int run();
	 

    

private:
    sf::RenderWindow& m_window;
    sf::Font m_font;
    sf::Text m_startButton;
    sf::Text m_speedLabel;
    std::vector<sf::Text> m_speedOptions;
    int m_selectedSpeedIndex;
    std::vector<float> m_speedValues;
   
    
 
};
