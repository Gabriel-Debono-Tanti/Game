#include <SFML/Graphics.hpp>
#include "Biome.hpp"
#include "Object.hpp"

#include <cstdlib>
#include <vector>
#include <math.h>
using namespace std;
using namespace sf;




Color c(0,202,27);
Color c2(67,202,0);
Color magic(58, 228, 205);
Biome grassland(Vector2f(700, 700), Color::Green);

Biome desert(Vector2f(600, 600), Color::Yellow);
Biome birchforest(Vector2f(950, 950),c2);
Biome countryland(Vector2f(900, 900), c); 
Biome magicalforest(Vector2f(900, 900), magic);


int main(){
    
    sf::View view1;
    view1.setSize(1000.f, 1000.f);

// zoom the view relatively to its current size (apply a factor 0.5, so its final size is 600x400)
    view1.zoom(4);
    ContextSettings settings;
    
    RenderWindow window(VideoMode(1000, 1000), "New Game", Style::Titlebar | Style::Close, settings);
    window.setFramerateLimit(60);
    grassland.setPos(Vector2f(-1000,550));
    desert.setPos(Vector2f(500,1000));
    birchforest.setPos(Vector2f(-1200,-1200));
    countryland.setPos(Vector2f(-400,300));
    magicalforest.setPos(Vector2f(1000, 200));
    Texture t;
    t.loadFromFile("Art/Trees/tree1.png");

    //Sprite oaktree[100];
   // for(int i = 0; i < 100; i++){
    //    int x = rand()%(480+400 + 1) - 400;
    //    int y = rand()%(1200-300 + 1) + 300;
    //    oaktree[i].setPosition(x, y);
     //   oaktree[i].setTexture(t);
        
   // }
    std::vector<Object> oaktrees;

    // Generate 10 randomly generated sprites
    for (int i = 0; i < 200; ++i)
    {
        // Use random number generators to generate random values for the sprite parameters
        int x = rand()%(480+400 + 1) - 400;
        int y = rand()%(1200-300 + 1) + 300;
        int health = 0;
        // Create an SFML sprite and set its parameters
        Object tree(t, Vector2f((x), (y)), 500);
        // Push the sprite into the vector
        oaktrees.push_back(tree);
    }
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();
            
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF = window.mapPixelToCoords(mousePos);
                for (auto& sprite : oaktrees) {
            if (sprite.contains(Vector2f(mousePosF))) {
                sprite.takeDamage(10);
                if (sprite.m_health <= 0) {
                    // destroy sprite
                    auto it = std::find_if(oaktrees.begin(), oaktrees.end(), [&sprite](const Object& s) { return &s == &sprite; });
                    oaktrees.erase(it);
                }
            }
        }
    } 
        }
        window.clear(sf::Color::Black);
        grassland.drawTo(window);
        desert.drawTo(window);
        birchforest.drawTo(window);
        countryland.drawTo(window);
        magicalforest.drawTo(window);
        //for (unsigned int i = 0u; i < 50; ++i)
            //window.draw(oaktree[i]);

        window.setView(view1);

        for (auto& sprite : oaktrees)
    {
        for (auto& otherSprite : oaktrees)
        {
            if (&sprite == &otherSprite)
          {
                continue;
            }

            // Calculate the distance between the sprites
            sf::Vector2f displacement = sprite.getPosition() - otherSprite.getPosition();
            float distance = std::sqrt(displacement.x * displacement.x + displacement.y * displacement.y);

            // If the sprites are colliding, subtract damage from the sprite's health
            if (distance < sprite.getRadius() + otherSprite.getRadius())
            {
                sprite.takeDamage(std::rand() % 10 + 1);
            }
        }
    }
    // Remove any sprites whose health has reached 0 or less
    oaktrees.erase(std::remove_if(oaktrees.begin(), oaktrees.end(), [](const Object& sprite) {
        return !sprite.isAlive();
    }), oaktrees.end());
          for (auto& sprite : oaktrees)
    {
        sprite.draw(window);
    }
   
        window.display();
    }
    return 0;
}
