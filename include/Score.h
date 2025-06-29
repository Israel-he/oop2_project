#include <SFML/Graphics.hpp>
class Score
{
public:
	Score();
	
	void addPoints(int points);
 
	int getScore() const;
	void setLevel(int level);

	void reset();

	void setPosition(const sf::Vector2f& position);
	void draw(sf::RenderWindow& window);

private:
	int score; // נקודות
	sf::Font m_font; // גופן לשימוש בטקסטים
	sf::Text m_text; // טקסט להצגה בחלון

	sf::Text m_textLevel;
	int m_level = 0; // רמה נוכחית
};