#include "GameWindow.h"

class GameOver : public GameWindow
{
public:
	GameOver(std::string& text);
 
	virtual void draw() ;
	virtual void createText();
	 
};
