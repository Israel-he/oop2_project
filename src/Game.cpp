#include "Game.h"
#include <string>
#include <algorithm> // std::min, std::max

//========== Constructor ==========
Game::Game()
    : m_high(600), m_width(800),
    m_texture(),
    m_snake(m_texture.getTexture(ID::face1)),
    m_board(m_texture.getTexture(ID::grass))
{
    m_startButton.setPosition(m_width / 2 - m_startButton.getGlobalBounds().width / 2,
        m_high / 2 - m_startButton.getGlobalBounds().height / 2);

    createWindow();
    run();
}

//========== Constructor with speed ==========
Game::Game(float playerSpeed)
    : m_high(600), m_width(800),
    m_texture(),
    m_snake(m_texture.getTexture(ID::face1)),
    m_board(m_texture.getTexture(ID::grass))
{
    m_snake.setSpeed(playerSpeed);
    createWindow();
    run();
}

//========== createStartWindow ==========
void Game::createStartWindow()
{
    m_startWindow.create(sf::VideoMode(m_width, m_high), "Start Game", sf::Style::Close | sf::Style::Resize);
    m_startWindow.setFramerateLimit(60);
}

//========== createWindow ==========
void Game::createWindow()
{
    m_window.create(sf::VideoMode(m_width, m_high), "Game", sf::Style::Close | sf::Style::Resize);
    m_window.setFramerateLimit(60);

    // הגדרות View
    m_view.setSize(static_cast<float>(m_width), static_cast<float>(m_high)); // גודל המצלמה
    m_view.setCenter(m_snake.getPosition()); // מתחיל במיקום הנחש
    m_window.setView(m_view);
}

//========== loadTextures ==========
void Game::loadTextures()
{
    // לא בשימוש כרגע
}

//========== run ==========
void Game::run()
{
    while (m_window.isOpen() || m_startWindow.isOpen())
    {
        m_deltaTime = m_clock.restart().asSeconds();

        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
                m_startWindow.close();
            }
        }

        m_snake.move(m_deltaTime);
        update();
        render();
    }
}

//========== update ==========
void Game::update()
{
    // קבל גודל התצוגה (VIEW)
    sf::Vector2f viewSize = m_view.getSize();
    float halfW = viewSize.x / 2.f;
    float halfH = viewSize.y / 2.f;

    // מיקום הנחש (המרכז הרצוי)
    sf::Vector2f center = m_snake.getPosition();

    // גבולות התמונה של הרקע (חשוב לעדכן לפי הגודל האמיתי!)
    sf::Vector2f backgroundSize(1600.f, 1200.f);

    // הגבל את תזוזת המצלמה (VIEW) שלא תצא מגבולות הרקע
    center.x = std::max(halfW, std::min(center.x, backgroundSize.x - halfW));
    center.y = std::max(halfH, std::min(center.y, backgroundSize.y - halfH));

    m_view.setCenter(center);
    m_window.setView(m_view);
}

//========== render ==========
void Game::render()
{
    // ציור משחק
    m_window.clear(sf::Color::Black);

    m_board.draw(m_window);
    m_snake.draw(m_window);

    m_window.display();

    // ציור חלון התחלה (אם פתוח)
    if (m_startWindow.isOpen())
    {
        m_startWindow.clear(sf::Color::Black);
        m_startWindow.draw(m_startButton);
        m_startWindow.display();
    }
}
