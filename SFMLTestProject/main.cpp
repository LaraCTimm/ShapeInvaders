#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "Majestic Window");
    
    sf::RectangleShape rectangle(sf::Vector2f(800,800));
    
    // Set bullet attributes
//    rectangle.setOutlineThickness(2);
//    rectangle.setOutlineColor(sf::Color::Green);
    rectangle.setFillColor(sf::Color::White);
//    rectangle.setOrigin(sf::Vector2f(0,0));
//    rectangle.setRotation(_angle*2);
    rectangle.setPosition(0, 0);
    
    sf::Texture texture;
    texture.loadFromFile("backgroundSprite.png");
//    sf::Sprite sprite;
//    sprite.setTexture(texture);
    rectangle.setTexture(&texture);
    sf::IntRect rectSourceSprite(0, 0, 450,450);
    rectangle.setTextureRect(rectSourceSprite);
    
    sf::Clock clock;
    
    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        
        float radius = 50;
        sf::CircleShape circle(radius,3);
        circle.setOrigin(radius, radius);
        circle.setPosition(100,100);
        sf::RectangleShape rectangle1(sf::Vector2f(50,50));
        rectangle1.setOrigin(sf::Vector2f(25,25));
        rectangle1.setFillColor(sf::Color(255,0,65));
        rectangle1.setPosition(sf::Vector2f(100, 100));
        
        if (clock.getElapsedTime().asSeconds() > 0.4f)
        {
            if (rectSourceSprite.left == 3150)
                rectSourceSprite.left = 0;
            else
                 rectSourceSprite.left += 450;
                 
            rectangle.setTextureRect(rectSourceSprite);
            clock.restart();
        }
        
        
        window.clear(sf::Color::Black);
        window.draw(rectangle);
        
        window.draw(circle);
        window.draw(rectangle1);

        window.display();
    }
}

