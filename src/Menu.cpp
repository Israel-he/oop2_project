#include "Menu.h"


Menu::Menu(sf::RenderWindow& window)
    : m_window(window), m_selectedSpeedIndex(0), m_speedValues{ 180.f, 200.f, 280.f }
    , m_startButton(m_font, "START", 36, sf::Vector2f(window.getSize().x / 2.f - 60, 100))
{
    m_font.loadFromFile("C:/Windows/Fonts/arial.ttf");

    // חשב את מרכז המסך
    sf::Vector2u windowSize = m_window.getSize();
    float centerX = windowSize.x / 2.0f;

    // מקם את כפתור "Start" במרכז המסך


    // מקם את הטקסט "Select Player Speed" במרכז המסך
    m_speedLabel.setFont(m_font);
    m_speedLabel.setString("Select Speed and press START to play");
    m_speedLabel.setCharacterSize(24);
    m_speedLabel.setPosition(centerX - m_speedLabel.getGlobalBounds().width / 2, 200);

    // מקם את האפשרויות במרכז המסך
    std::vector<std::string> speedTexts = { "Slow", "Normal", "Fast" };
    for (size_t i = 0; i < speedTexts.size(); ++i) {
        sf::Text option;
        option.setFont(m_font);
        option.setString(speedTexts[i]);
        option.setCharacterSize(24);
        option.setPosition(centerX - option.getGlobalBounds().width / 2, 250 + static_cast<float>(i) * 40);
        m_speedOptions.push_back(option);
    }
}

void Menu::draw() {
    m_startButton.draw(m_window);
    m_window.draw(m_speedLabel);
    for (size_t i = 0; i < m_speedOptions.size(); ++i) {
        if (i == m_selectedSpeedIndex)
            m_speedOptions[i].setFillColor(sf::Color::Red);
        else
            m_speedOptions[i].setFillColor(sf::Color::White);
        m_window.draw(m_speedOptions[i]);
    }
}


void Menu::handleEvent(const sf::Event& event, bool& startGame, float& playerSpeed) {
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Up) {
            if (m_selectedSpeedIndex > 0) m_selectedSpeedIndex--;
        }
        else if (event.key.code == sf::Keyboard::Down) {
            if (m_selectedSpeedIndex < static_cast<int>(m_speedOptions.size()) - 1) m_selectedSpeedIndex++;
        }
    }
    else if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(m_window);
        if (m_startButton.isMouseOver(m_window, mousePos)) {
			m_startButton.setFillColor(sf::Color::Green); // Change color to indicate selection
            startGame = true;
            playerSpeed = m_speedValues[m_selectedSpeedIndex];
        }
    }
}

//==================================
int Menu::run()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");

    while (window.isOpen())
    {
        // --- תפריט ---
        Menu menu(window);
        bool m_startGame = false;
        float playerSpeed = 200.f; // Default

        while (window.isOpen() && !m_startGame) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed)
                    window.close();
                menu.handleEvent(event, m_startGame, playerSpeed);

            }
            if (!m_gameOverWindowOpen)//??
            {
                window.clear();
                menu.draw();
                window.display();
            }

        }

        if (!window.isOpen())
            break;

        // --- משחק ---
        try
        {
            Game m_game(playerSpeed);
            m_game.run();
        }
        catch (const std::exception& e)
        {
            std::cerr << "Error: " << e.what() << std::endl;
            return EXIT_FAILURE;
        }
    }
}







































//#include "Menu.h"
//
//
//Menu::Menu(sf::RenderWindow& window)
//    : m_window(window), m_selectedSpeedIndex(0), m_speedValues{ 180.f, 200.f, 280.f } 
//{
//    m_font.loadFromFile("C:/Windows/Fonts/arial.ttf");
//
//    // חשב את מרכז המסך
//    sf::Vector2u windowSize = m_window.getSize();
//    float centerX = windowSize.x / 2.0f;
//
//    // מקם את כפתור "Start" במרכז המסך
//    m_startButton.setFont(m_font);
//    m_startButton.setString("Welcome to The Snake");
//    m_startButton.setCharacterSize(36);
//    m_startButton.setPosition(centerX - m_startButton.getGlobalBounds().width / 2, 100);
//
//    // מקם את הטקסט "Select Player Speed" במרכז המסך
//    m_speedLabel.setFont(m_font);
//    m_speedLabel.setString("Select Speed and press ENTER to play");
//    m_speedLabel.setCharacterSize(24);
//    m_speedLabel.setPosition(centerX - m_speedLabel.getGlobalBounds().width / 2, 200);
//
//    // מקם את האפשרויות במרכז המסך
//    std::vector<std::string> speedTexts = { "Slow", "Normal", "Fast" };
//    for (size_t i = 0; i < speedTexts.size(); ++i) {
//        sf::Text option;
//        option.setFont(m_font);
//        option.setString(speedTexts[i]);
//        option.setCharacterSize(24);
//        option.setPosition(centerX - option.getGlobalBounds().width / 2, 250 + static_cast<float>(i) * 40);
//        m_speedOptions.push_back(option);
//    }
//}
//
//void Menu::draw() {
//    m_window.draw(m_startButton);
//    m_window.draw(m_speedLabel);
//    for (size_t i = 0; i < m_speedOptions.size(); ++i) {
//        if (i == m_selectedSpeedIndex)
//            m_speedOptions[i].setFillColor(sf::Color::Red);
//        else
//            m_speedOptions[i].setFillColor(sf::Color::White);
//        m_window.draw(m_speedOptions[i]);
//    }
//}
//
//void Menu::handleEvent(const sf::Event& event, bool& startGame, float& playerSpeed) {
//    if (event.type == sf::Event::KeyPressed) {
//        if (event.key.code == sf::Keyboard::Up) {
//            if (m_selectedSpeedIndex > 0) m_selectedSpeedIndex--;
//        }
//        else if (event.key.code == sf::Keyboard::Down) {
//            if (m_selectedSpeedIndex < static_cast<int>(m_speedOptions.size()) - 1) m_selectedSpeedIndex++;
//        }
//        else if (event.key.code == sf::Keyboard::Enter) {
//            // If "Start" is selected (simulate with Enter)
//            startGame = true;
//            playerSpeed = m_speedValues[m_selectedSpeedIndex];
//        }
//    }
//}
////==================================
//int Menu::run()
//{
//    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
//
//    while (window.isOpen())
//    {
//        // --- תפריט ---
//        Menu menu(window);
//        bool m_startGame = false;
//        float playerSpeed = 200.f; // Default
//
//        while (window.isOpen() && !m_startGame) {
//            sf::Event event;
//            while (window.pollEvent(event)) {
//                if (event.type == sf::Event::Closed)
//                    window.close();
//                menu.handleEvent(event, m_startGame, playerSpeed);
//                 
//            }
//            if (!m_gameOverWindowOpen)
//            {
//                window.clear();
//                menu.draw();
//                window.display();
//            }
//           
//        }
//
//        if (!window.isOpen())
//            break;
//
//        // --- משחק ---
//        try
//        {
//            Game m_game(playerSpeed);
//            m_game.run();
//        }
//        catch (const std::exception& e)
//        {
//            std::cerr << "Error: " << e.what() << std::endl;
//            return EXIT_FAILURE;
//        }
//    }
//}
//
//
//
// 