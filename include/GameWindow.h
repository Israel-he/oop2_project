
#include <SFML/Graphics.hpp>
#include <string>
class GameWindow
{
public:

	GameWindow(std::string& text);

	void createWindow();
	virtual ~GameWindow() = default;
	bool isOpen() const;
	virtual void draw() = 0;
	virtual void setText();
	virtual void createText() = 0;
	sf::RenderWindow& getWindow() { return m_window; }

protected:

	sf::RenderWindow m_window; // חלון המשחק
	sf::View m_view; // המצלמה של המשחק
	int m_width; // רוחב החלון
	int m_height; // גובה החלון
	sf::Font m_font; // גופן לשימוש בטקסטים
	sf::Text m_text; // טקסט להצגה בחלון
	std::string m_txt;
	sf::Vector2f m_textPosition; // מיקום הטקסט בחלון
};