#include <string>  

namespace ID  
{  
	//constexpr std::string grass = "grass";
   const char WALL = '#';
   const char FOOD = '*';
   constexpr char PLAYER = 'P';
   constexpr char BODY = 'B';
   constexpr char E_FOOD = 'E'; // מזון נוסף
   constexpr int WITH_WALL = 20;  
   constexpr int HIGHT_WALL = 20;  
   constexpr int WITH_FOOD = 29;
   constexpr int HIGHT_FOOD = 28;
   constexpr int WITH_PLAYER = 34;
   constexpr int HIGHT_PLAYER = 54;
   constexpr int WITH_BODY = 22;
   constexpr int HIGHT_BODY = 40;
   constexpr int NUM_OF_FOOD = 2;
   constexpr int NUM_OF_E_FOOD = 1;
   constexpr int POINTS_PER_FOOD = 1; // נקודות עבור כל מזון שנאכל
   constexpr int POINTS_PER_E_FOOD = 2;
   constexpr int WITH_E_FOOD = 29;
   constexpr int HIGHT_E_FOOD = 28;
   constexpr int WIN_SCORE = 5; // ניקוד לניצחון
}
