#include "GameWindow.h"

class GameOver : public GameWindow
{
public:
	GameOver(std::string& text);

	void draw() override;
	void createText() override;
	 
};
