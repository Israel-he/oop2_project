#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include "Game.h"

class Menu {
public:

    Menu(sf::RenderWindow& window);
    void draw();
    void handleEvent(const sf::Event& event, bool& startGame, float& playerSpeed);
    int run();
	 

    void createGameOverWindow();
    void setTextGameOver();

private:
    sf::RenderWindow& m_window;
    sf::Font m_font;
    sf::Text m_startButton;
    sf::Text m_speedLabel;
    std::vector<sf::Text> m_speedOptions;
    int m_selectedSpeedIndex;
    std::vector<float> m_speedValues;
    bool m_startGame = false;
    Game m_game;
    //game over window
    sf::RenderWindow m_gameOverWindow;
    sf::Font m_fontGameOver;
    sf::Text m_gameOverText;
};
