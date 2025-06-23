#include "Game.h"
#include <string>
#include <algorithm> // std::min, std::max
#include "Menu.h"

//========== Constructor with speed ==========
Game::Game(float playerSpeed)
    :m_high(600), m_width(800),
	m_readFromFile("level1.txt"), m_gameOver(m_txtGameOver)
    
{
	 
	m_snake = m_readFromFile.extractSnake();  
	m_walls = m_readFromFile.getWalls();
	m_foods = m_readFromFile.getFood();
    getTexGrassTexture(m_readFromFile.getGrassTexture());
	getTexPhotoTexture(m_readFromFile.getPhotoTexture());

	m_snake->setSpeed(playerSpeed);
    createWindow();
    run();
}
 
//========== createWindow ==========
void Game::createWindow()
{
    m_window.create(sf::VideoMode(m_width, m_high), "Game", sf::Style::Close | sf::Style::Resize);
    m_window.setFramerateLimit(60);

    // הגדרות View
    m_view.setSize(static_cast<float>(m_width), static_cast<float>(m_high)); // גודל המצלמה
    m_view.setCenter(m_snake->getPosition()); // מתחיל במיקום הנחש
    m_window.setView(m_view);
}

//========== getTexGrassTexture ==========
void Game::getTexGrassTexture(sf::Texture& texture)
{ 
	m_grassSprite.setTexture(texture);
	m_grassSprite.setPosition(0.f, 0.f);  
}

//========== getTexPhotoTexture ==========
void Game::getTexPhotoTexture(sf::Texture& texture)
{
    m_PhotoSprite = texture;
}

//========== loadTextures ==========
void Game::loadTextures()
{
    // לא בשימוש כרגע
}

//========== run ==========
void Game::run()
{
    while (m_window.isOpen())
    {
        m_deltaTime = m_clock.restart().asSeconds();

        sf::Event event;
        while (m_window.pollEvent(event)) // Poll events for both windows
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }

        }

        m_snake->move(m_deltaTime);
        handleEndChkCollisions(*m_snake);
        update();
        render();
    }
    while (m_gameOver.isOpen())
    {
        sf::Event event;
        while (m_gameOver.getWindow().pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_gameOver.getWindow().close(); // סגירת חלון סיום המשחק
                m_gameOverWindowOpen = false;
            }
        }
    }
}

//========== handleEndChkCollisions ==========
void Game::handleEndChkCollisions(GameObject& snake)
{
    for (const auto& wall : m_walls)
    {
        snake.handleCollision(*wall);
        if (snake.getIsDead()) // אם הנחש מת, יצא מהלולאה
        {
            snakeIsDead();
            return;
        }
    }

    for (const auto& food : m_foods)
    {
        snake.handleCollision(*food);
    }

    
	for (auto& food : m_foods)
	{
		if (food->getIsEaten()) // אם האוכל נאכל, הוסף ניקוד
		{
			m_score.addPoints( ID::POINTS_PER_FOOD);
			 
		}
	}
    std::erase_if(m_foods, [](auto& object)
        {
            return object->getIsEaten();
        });

    if (m_foods.size() <= ID::NUM_OF_FOOD)
    {
        m_posOfNewFood = getValidFoodPosition();
        m_foods.push_back(std::make_unique<Food>(m_PhotoSprite, m_posOfNewFood));
    }
    // בדוק אם הנחש פוגע בעצמו

    int sizeOfSnake = m_snake->getSnakeBodySize();

    for (int i = 0; i < sizeOfSnake; ++i)
    {
        snake.handleCollision(m_snake->getSnakeBody(i));
        if (snake.getIsDead()) // אם הנחש מת, יצא מהלולאה
        {
            snakeIsDead();
            return;
        }
    }
}

//========== snakeIsDead ==========
void Game::snakeIsDead()
{
    m_window.close();
	m_gameOver.createWindow(); // יצירת חלון סיום המשחק
	m_gameOver.createText(); // יצירת הטקסט בחלון סיום המשחק
    m_gameOverWindowOpen = true; // עדכון המצב של חלון סיום המשחק
}

//========== getValidFoodPosition ==========
// מחזיר מיקום רנדומלי חוקי לאוכל
sf::Vector2f Game::getValidFoodPosition() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> distX(25, 1570); // גבולות המשחק
    std::uniform_real_distribution<float> distY(25, 1170);

    while (true) {
        sf::Vector2f pos(distX(gen), distY(gen));
        bool valid = true;

        // בדוק חפיפה עם ראש הנחש
        if ((m_snake->getPosition() - pos).x < ID::WITH_PLAYER && (m_snake->getPosition() - pos).y < ID::HIGHT_PLAYER)
            valid = false;

        // בדוק חפיפה עם גוף הנחש
		for (int i = 0; i < m_snake->getSnakeBodySize(); ++i) {
			if ((m_snake->getSnakeBody(i).getPosition() - pos).x < 20 && (m_snake->getSnakeBody(i).getPosition() - pos).y < 20) {
				valid = false;
				break;
			}
		}
        
        // בדוק חפיפה עם אוכל קיים
        for (const auto& food : m_foods) {
            if ((food->getPosition() - pos).x < 20 && (food->getPosition() - pos).y < 20) {
                valid = false;
                break;
            }
        }

        if (valid)
            return pos;
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
    sf::Vector2f center = m_snake->getPosition();

    // גבולות התמונה של הרקע (חשוב לעדכן לפי הגודל האמיתי!)
    sf::Vector2f backgroundSize(1600.f, 1200.f);

    // הגבל את תזוזת המצלמה (VIEW) שלא תצא מגבולות הרקע
    center.x = std::max(halfW, std::min(center.x, backgroundSize.x - halfW));
    center.y = std::max(halfH, std::min(center.y, backgroundSize.y - halfH));
    
    m_view.setCenter(center);
    m_window.setView(m_view);
	// עדכן את מיקום הטקסט של הניקוד
    sf::Vector2f scorePos = m_view.getCenter();
    scorePos.x -= 350.f;
    scorePos.y += 250.f;
    m_score.setPosition(scorePos);
}
//========== render ==========
void Game::render()
{
    draw();

    if (m_gameOverWindowOpen)
    {
		m_gameOver.draw(); // ציור חלון סיום המשחק
    }
}
//========== draw ==========
void Game::draw()
{
    m_window.clear(sf::Color::Black);
    m_window.draw(m_grassSprite);
	m_score.draw(m_window); // ציור הניקוד
	//draw the walls
    for (const auto& wall : m_walls)
    {
        wall->draw(m_window);
    }
	//draw the food
    for (const auto& food : m_foods)
    {
        food->draw(m_window);
    }
    m_snake->draw(m_window);
    m_window.display();
}
