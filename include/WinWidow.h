#include "GameWindow.h"

class WinWidow : public GameWindow
{
public:

	WinWidow(std::string& text);
 
	 
	virtual void draw();
	virtual void createText() ;

};
