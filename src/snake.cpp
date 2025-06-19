#include "snake.h"
#include "io.h"
snake::snake(sf::Texture& head, sf::Vector2f& position)
    : MovingObject(head, position), m_speed(10.0f), m_direction(0.0f, 0.0f)
{
    // מיקום התחלתי של הראש
   // m_sprite.setPosition(100.0f, 100.0f);
    m_sprite.setTextureRect(sf::IntRect(14 + ID::WITH_PLAYER, 200, ID::WITH_PLAYER, ID::HIGHT_PLAYER));
    m_sprite.setOrigin(17.0f, 27.0f);

    // היסטוריית מיקומים - מתחיל עם מיקום הראש
    m_positionsHistory.push_back({ m_sprite.getPosition() });
   


    //// יצירת חוליות גוף התחלתיות
    //for (int i = 0; i < m_bodyCount; ++i)
    //{
    //    m_snakeBody.push_back(snakeBody(m_texture, posBody));
    //}
}

void snake::move(float deltaTime)
{
    m_countTime += deltaTime;
    if (m_countTime > m_changeTime) {
        changeSprite();
        m_countTime = 0.0f;
    }

    // עדכון כיוון לפי מקשי החצים
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        m_direction = sf::Vector2f(0.0f, -1.0f);
        m_sprite.setRotation(180.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        m_direction = sf::Vector2f(0.0f, 1.0f);
        m_sprite.setRotation(0.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        m_direction = sf::Vector2f(-1.0f, 0.0f);
        m_sprite.setRotation(90.f);
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        m_direction = sf::Vector2f(1.0f, 0.0f);
        m_sprite.setRotation(270.f);
    }

    // תזוזת הראש
    sf::Vector2f movement = m_direction * m_speed * deltaTime;
    m_sprite.move(movement);

    // הוספת מיקום ראש להיסטוריה
    m_positionsHistory.push_back({ m_sprite.getPosition() });

    if (m_positionsHistory.size() > 1000)
        m_positionsHistory.erase(m_positionsHistory.begin());

    // עדכון גוף הנחש לפי ההיסטוריה
    for (size_t i = 0; i < m_snakeBody.size(); ++i) {
        int index = static_cast<int>(m_positionsHistory.size()) - 1 - (i + 1) * m_spacing;
        int prevIndex = index - 1;

        if (index >= 0 && prevIndex >= 0) {
            sf::Vector2f current = m_positionsHistory[index].position;
            sf::Vector2f prev = m_positionsHistory[prevIndex].position;

            m_snakeBody[i].setPosition(current);

            sf::Vector2f delta = current - prev;
            float angle = std::atan2(delta.y, delta.x) * 180.f / 3.14159f;

            m_snakeBody[i].setRotation(angle + 90.f); // +90 כי החוליה מצביעה למעלה כברירת מחדל
        }
    }


}

void snake::draw(sf::RenderWindow& window)
{
    // ציור החוליות
    for (auto& part : m_snakeBody) {
        part.draw(window);
    }

    // ציור הראש
    window.draw(m_sprite);
}

void snake::changeSprite()
{
    m_sprite.setTextureRect(sf::IntRect(14 + ID::WITH_PLAYER * (m_rotation % 6), 200, ID::WITH_PLAYER, ID::HIGHT_PLAYER));
    m_rotation++;
    m_sprite.setOrigin(17.0f, 27.0f);
}

sf::Vector2f snake::getPosition()
{
    return m_sprite.getPosition();
}

void snake::setSpeed(float speed)
{
    m_speed = speed;
    setSpacing();
}

void snake::addBodyPart(sf::Texture& texture)
{
    // הוספת חוליה חדשה לפי המיקום של האחרונה בגוף
    sf::Vector2f pos = m_snakeBody.empty() ? m_sprite.getPosition() : m_snakeBody.back().getPosition();
    snakeBody newPart(texture, posBody);
    newPart.setPosition(pos);
    m_snakeBody.push_back(newPart);
}

//========setSpacing==========
void snake::setSpacing()
{
    if (m_speed == 280.f)
    {
		m_spacing = 7; // מרחק בין חוליות מהירות
		m_changeTime = 0.05f; // זמן בין שינויי ספרייט מהיר יותר
	}
	else if (m_speed == 200.f)
	{
		m_spacing = 9; // מרחק בין חוליות בינונית
        m_changeTime = 0.07f;
	}
    else
    {
        m_spacing = 12; // מרחק בין חוליות איטיות
    }
     
}

//========getSnakeBodySize==========
int snake::getSnakeBodySize() const
{
	return static_cast<int>(m_snakeBody.size());
}
//========getSnakeBody==========
snakeBody& snake::getSnakeBody(const int index)
{
	return m_snakeBody.at(index);
}




//========handleCollision==========
void snake::handleCollision(GameObject& gameObject)
{
	gameObject.handleCollision(*this);
}

//FOOD
void snake::handleCollision(Food& gameObject)
{
	// הוספת חוליה חדשה לגוף הנחש
	addBodyPart(m_texture);
	// הסרת המזון מהמשחק
 
}
















































//#include "snake.h"
//
//snake::snake(sf::Texture& head)
//	:MovingObject(head), m_speed(10.0f), m_direction(0.0f, 0.0f) 
//{
//     
//    m_sprite.setPosition(100.0f, 100.0f);  
//	m_bodyParts.push_back(sf::Vector2f(100.0f, 100.0f)); 
//	m_sprite.setPosition(m_bodyParts[0]); 
//   
//    m_sprite.setTextureRect(sf::IntRect(14+ 34 * (m_rotation%3), 200, 34, 54));
//    m_sprite.setOrigin(17.0f, 27.0f);
//
//    m_snakeBody.push_back(snakeBody(m_texture));   
//}
//
////==========move===========
////void snake::move(float deltaTime)
////{
////	m_countTime += deltaTime;
////	if (m_countTime > m_changeTime) 
////    {
////        changeSprite();
////		m_countTime = 0.0f;  
////	}
////    // עדכון כיוון לפי קלט מהחיצים - זוויות נכונות לפי SFML
////    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
////        m_direction = sf::Vector2f(0.0f, -1.0f);
////        m_sprite.setRotation(180.f);
////        m_sprite.move(0, m_direction.y * m_speed * deltaTime);
////		//m_position.y = m_direction.y * m_speed * deltaTime;
////        //m_position.x = 0;
////       
////    }
////    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
////        m_direction = sf::Vector2f(0.0f, 1.0f);
////        m_sprite.setRotation(0.f);
////        m_sprite.move(0, m_direction.y * m_speed * deltaTime);
////		//m_position.y = m_direction.y * m_speed * deltaTime;
////       // m_position.x = 0;
////       // m_sprite.setRotation(0.f);
////    }
////    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
////        m_direction = sf::Vector2f(-1.0f, 0.0f);
////		m_sprite.setRotation(90.f);
////		m_sprite.move(m_direction.x * m_speed * deltaTime, 0);
////	/*	m_position.x = m_direction.x * m_speed * deltaTime;
////        m_position.y = 0;
////        m_sprite.setRotation(90.f);*/
////    }
////    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
////        m_direction = sf::Vector2f(1.0f, 0.0f);
////		m_sprite.setRotation(270.f);
////		m_sprite.move(m_direction.x * m_speed * deltaTime, 0);
////	/*	m_position.x = m_direction.x * m_speed * deltaTime;
////        m_position.y = 0;
////        m_sprite.setRotation(270.f);*/
////    }
////
////    // עדכון מיקום הראש
////    //sf::Vector2f movement = m_direction * m_speed * deltaTime;
////    //m_sprite.move(m_position);
////
//// 
////	m_snakeBody[0].setPosition(m_direction,m_sprite.getPosition()); // עדכון מיקום החוליה הראשונה (הראש)
////	m_snakeBody[0].move(deltaTime); // עדכון המיקום של החוליה הראשונה
////
////    // עדכון מיקום הגוף (פשוט: כל חלק עוקב אחרי הקודם)
//// /*   if (!m_bodyParts.empty()) {
////        m_bodyParts[0] = m_sprite.getPosition();
////    }*/
//// 
////    /*for (size_t i = 0; i < m_body.size(); ++i) {
////        sf::Vector2f temp = m_body[i].getPosition();
////        m_body[i].setPosition(prevPos);
////        prevPos = temp;
////    }*/
////}
//
//
//
//
////================================
//void snake::move(float deltaTime)
//{
//    m_countTime += deltaTime;
//    if (m_countTime > m_changeTime)
//    {
//        changeSprite();
//        m_countTime = 0.0f;
//    }
//
//    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
//        m_direction = sf::Vector2f(0.0f, -1.0f);
//        m_sprite.setRotation(180.f);
//    }
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
//        m_direction = sf::Vector2f(0.0f, 1.0f);
//        m_sprite.setRotation(0.f);
//    }
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
//        m_direction = sf::Vector2f(-1.0f, 0.0f);
//        m_sprite.setRotation(90.f);
//    }
//    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
//        m_direction = sf::Vector2f(1.0f, 0.0f);
//        m_sprite.setRotation(270.f);
//    }
//
//
//    sf::Vector2f movement = m_direction * m_speed * deltaTime;
//    m_sprite.move(movement);
//
//	m_snakeBody[0].getInfo(movement);
//	m_snakeBody[0].move(deltaTime);  
//
//}
////==========changeSprite===========
//void snake::changeSprite()
//{
//     
//   
//    m_sprite.setTextureRect(sf::IntRect(14 + 34 * (m_rotation % 6), 200, 34, 54));
//    m_rotation++;
//    m_sprite.setOrigin(17.0f, 27.0f);
//}
//
////==========getPosition===========
//sf::Vector2f snake::getPosition()
//{
//    return m_sprite.getPosition();
//}
//
////==========setSpeed===========
//void snake::setSpeed(float speed)
//{
//    m_speed = speed;
//}
//
////==========addBodyPart===========
////void snake::addBodyPart(sf::Texture& texture)
////{
////    // הוסף חוליה חדשה בסוף הגוף, במיקום של החוליה האחרונה
////    sf::Vector2f pos = m_body.empty() ? m_sprite.getPosition() : m_body.back().getPosition();
////    m_body.emplace_back(texture);
////    m_body.back().setPosition(pos);
////
////}
//    
////==========draw===========	
//void snake::draw(sf::RenderWindow& window)
//{
//	// Draw the snake body parts
//    for (auto& part : m_snakeBody) {
//        part.draw(window);
//    }
//
//	// Draw the head of the snake
//	window.draw(m_sprite);
//
//   
//}
//
//
