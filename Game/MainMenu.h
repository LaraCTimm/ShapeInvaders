#include <SFML/Graphics.hpp>

#define MAX_MENU_ITEMS 3

class MainMenu
{
public:
	MainMenu(float width, float height);
	~MainMenu();
	
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text text[MAX_MENU_ITEMS];
	
};