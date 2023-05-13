#include <SFML/Graphics.hpp>
#include "Biome.hpp"
#include "Object.hpp"

#include "JSONlibrary/json.hpp"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <math.h>
#include <ctime>

using namespace std;
using namespace sf;


Color dd(111, 111, 111);
Color cw(89, 176, 13);
Color c(0,202,27);
Color c2(67,202,0);
Color magic(58, 228, 205);
Color maple(103, 137, 24);
Color cdb(33, 78, 211);
Color a(132, 8, 16);
Color co(8, 146, 208);
Color swa(35, 40, 0);
Color ta(0, 66, 37);
Biome grassland(Vector2f(700, 700), Color::Green);
Biome desert(Vector2f(600, 600), Color::Yellow);
Biome birchforest(Vector2f(950, 950),c2);
Biome countryland(Vector2f(900, 900), c); 
Biome magicalforest(Vector2f(900, 900), magic);
Biome mapleforest(Vector2f(900, 950), maple);
Biome CherryWoods(Vector2f(800, 1350), cw);
Biome Moun(Vector2f(1600, 650), Color::Black);
Biome cold(Vector2f(700, 1000), Color::White);
Biome flower(Vector2f(500, 700), Color::Green);
Biome DeathD(Vector2f(900, 900), dd);
Biome CB(Vector2f(400, 400), cdb);

Biome Taiga(Vector2f(1000, 800), ta);
Biome Swamp(Vector2f(500, 500), swa);
Biome Al(Vector2f(650, 650), a);
Biome Com(Vector2f(600, 600), co);
int main(){
     
    time_t now = time(0);
    tm *ltm = localtime(&now);
    sf::View view1;
    view1.setSize(1000.f, 1000.f);

// zoom the view relatively to its current size (apply a factor 0.5, so its final size is 600x400)
    view1.zoom(6);
    ContextSettings settings;
    
    RenderWindow window(VideoMode(800, 800), "New Game", Style::Titlebar  | Style::Close, settings);
    window.setFramerateLimit(60);
    grassland.setPos(Vector2f(-1000,550));
    desert.setPos(Vector2f(500,1000));
    birchforest.setPos(Vector2f(-1200,-1200));
    countryland.setPos(Vector2f(-400,300));
    magicalforest.setPos(Vector2f(1000, 200));
    mapleforest.setPos(Vector2f(-300, -1150));
    CherryWoods.setPos(Vector2f(1200, -1150));
    Moun.setPos(Vector2f(-400, -300));
    cold.setPos(Vector2f(600, -1150));
    flower.setPos(Vector2f(500, 350));
    DeathD.setPos(Vector2f(-1300, -300));
    CB.setPos(Vector2f(-2000, 2500));
    Swamp.setPos(Vector2f(-1000,1250));
    Taiga.setPos(Vector2f(-500,1200));
    Al.setPos(Vector2f(2000, 2400));
    Com.setPos(Vector2f(-2000, -2000));
    Texture t;
    t.loadFromFile("Art/Trees/tree1.png");
    Texture cherryt;
    cherryt.loadFromFile("Art/Trees/tree6.png");
    Texture Bircht;
    Bircht.loadFromFile("Art/Trees/tree2.png");
    Texture Maplet;
    Maplet.loadFromFile("Art/Trees/tree4.png");
    Texture bonet;
    bonet.loadFromFile("Art/Trees/bonetree.png");
    //Sprite oaktree[100];
   // for(int i = 0; i < 100; i++){
    //    int x = rand()%(480+400 + 1) - 400;
    //    int y = rand()%(1200-300 + 1) + 300;
    //    oaktree[i].setPosition(x, y);
     //   oaktree[i].setTexture(t);
        
   // }
   auto month =  1 + ltm->tm_mon;
   auto day= ltm->tm_mday;
    std::vector<Object> oaktrees;
    std::vector<Object> cherrytrees;
    std::vector<Object> Birchtrees;
    std::vector<Object> Mapletrees;
    std::vector<Object> bonetrees;
        for (int i = 0; i < 200; ++i)
         {
            int x = rand()% ((int)(countryland.biome.getSize().x)/2+30-(int)(countryland.biome.getPosition().x) - 1) + countryland.biome.getPosition().x;
            int y = rand()% ((int)(countryland.biome.getSize().y)+260-(int)(countryland.biome.getPosition().y) - 1) + countryland.biome.getPosition().y;
            Object tree(t, Vector2f((x), (y)), 500);
        // Push the sprite into the vector
            oaktrees.push_back(tree);
        }
        for (int i = 0; i < 200; ++i)
         {
            int x = rand()% ((int)(CherryWoods.biome.getSize().x)/2+30-(int)(CherryWoods.biome.getPosition().x) - 1) + CherryWoods.biome.getPosition().x;
            int y = rand()% ((int)(CherryWoods.biome.getSize().y)/6-100-(int)(CherryWoods.biome.getPosition().y) - 1) + CherryWoods.biome.getPosition().y;
            Object tree(cherryt, Vector2f((x), (y)), 10000);
        // Push the sprite into the vector
            cherrytrees.push_back(tree);
        }
        for (int i = 0; i < 200; ++i)
         {
            int x = rand()% ((int)(birchforest.biome.getSize().x)/15-300-(int)(birchforest.biome.getPosition().x) - 1) + birchforest.biome.getPosition().x;
            int y = rand()% ((int)(birchforest.biome.getSize().y)/100-330-(int)(birchforest.biome.getPosition().y) - 1) + birchforest.biome.getPosition().y;
            Object tree(Bircht, Vector2f((x), (y)), 10000);
        // Push the sprite into the vector
            Birchtrees.push_back(tree);
        }
        
        for (int i = 0; i < 200; ++i)
         {
            int x = rand()% ((int)(mapleforest.biome.getSize().x)/2-(int)(mapleforest.biome.getPosition().x) - 1) + mapleforest.biome.getPosition().x + 100;
            int y = rand()% ((int)(mapleforest.biome.getSize().y)/100-330-(int)(mapleforest.biome.getPosition().y) - 1) + mapleforest.biome.getPosition().y;
            Object tree(Maplet, Vector2f((x), (y)), 10000);
        // Push the sprite into the vector
            Mapletrees.push_back(tree);
        }
        for (int i = 0; i < 200; ++i)
         {
            int x = rand()% ((int)(DeathD.biome.getSize().x)/2-850-(int)(DeathD.biome.getPosition().x) - 1) + DeathD.biome.getPosition().x;
            int y = rand()% ((int)(DeathD.biome.getSize().y)/2+120-(int)(DeathD.biome.getPosition().y) - 1) + DeathD.biome.getPosition().y;
            Object tree(bonet, Vector2f((x), (y)), 1000);
        // Push the sprite into the vector
            bonetrees.push_back(tree);
        }

    
    while (window.isOpen())
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            
            if (event.type == sf::Event::Closed)
                window.close();
            
            // and align shape
        
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
                for (auto& sprite : cherrytrees) {
                    if (sprite.contains(Vector2f(mousePosF))) {
                        sprite.takeDamage(10);
                        if (sprite.m_health <= 0) {
                    // destroy sprite
                            auto it = std::find_if(cherrytrees.begin(), cherrytrees.end(), [&sprite](const Object& s) { return &s == &sprite; });
                            cherrytrees.erase(it);
                        }
                    }   
                }
                for (auto& sprite : Birchtrees) {
                    if (sprite.contains(Vector2f(mousePosF))) {
                        sprite.takeDamage(10);
                        if (sprite.m_health <= 0) {
                    // destroy sprite
                            auto it = std::find_if(Birchtrees.begin(), Birchtrees.end(), [&sprite](const Object& s) { return &s == &sprite; });
                            Birchtrees.erase(it);
                        }
                    }   
                }
                 for (auto& sprite : Mapletrees) {
                    if (sprite.contains(Vector2f(mousePosF))) {
                        sprite.takeDamage(10);
                        if (sprite.m_health <= 0) {
                    // destroy sprite
                            auto it = std::find_if(Mapletrees.begin(), Mapletrees.end(), [&sprite](const Object& s) { return &s == &sprite; });
                            Mapletrees.erase(it);
                        }
                    }   
                }
                for (auto& sprite : bonetrees) {
                    if (sprite.contains(Vector2f(mousePosF))) {
                        sprite.takeDamage(10);
                        if (sprite.m_health <= 0) {
                    // destroy sprite
                            auto it = std::find_if(bonetrees.begin(), bonetrees.end(), [&sprite](const Object& s) { return &s == &sprite; });
                            bonetrees.erase(it);
                        }
                    }   
                }
            } 
        }
        window.clear(sf::Color::Blue);
        
        mapleforest.drawTo(window);
        grassland.drawTo(window);
        desert.drawTo(window);
        birchforest.drawTo(window);
        countryland.drawTo(window);
        
        
        cold.drawTo(window);
        flower.drawTo(window);
        Moun.drawTo(window);
        countryland.drawTo(window);
        DeathD.drawTo(window);
        Swamp.drawTo(window);
        Taiga.drawTo(window);
        Al.drawTo(window);
        Com.drawTo(window);
        CherryWoods.drawTo(window);
        magicalforest.drawTo(window);
        //for (unsigned int i = 0u; i < 50; ++i)
            //window.draw(oaktree[i]);

        window.setView(view1);
        if(day == 6 && month == 5){
            CB.drawTo(window);
        }
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
    for (auto& sprite : cherrytrees)
    {
        for (auto& otherSprite : cherrytrees)
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
    for (auto& sprite : Birchtrees)
    {
        for (auto& otherSprite : Birchtrees)
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
    for (auto& sprite : Mapletrees)
    {
        for (auto& otherSprite : Mapletrees)
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
    for (auto& sprite : bonetrees)
    {
        for (auto& otherSprite : bonetrees)
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
    cherrytrees.erase(std::remove_if(cherrytrees.begin(), cherrytrees.end(), [](const Object& sprite) {
        return !sprite.isAlive();
    }), cherrytrees.end());
    Birchtrees.erase(std::remove_if(Birchtrees.begin(), Birchtrees.end(), [](const Object& sprite) {
        return !sprite.isAlive();
    }), Birchtrees.end());
    Mapletrees.erase(std::remove_if(Mapletrees.begin(), Mapletrees.end(), [](const Object& sprite) {
        return !sprite.isAlive();
    }), Mapletrees.end());
    bonetrees.erase(std::remove_if(bonetrees.begin(), bonetrees.end(), [](const Object& sprite) {
        return !sprite.isAlive();
    }), bonetrees.end());
    for (auto& sprite : oaktrees)
    {
        sprite.draw(window);
    }
    for (auto& sprites : cherrytrees)
    {
        sprites.draw(window);
    }
    for (auto& sprites : Birchtrees)
    {
        sprites.draw(window);
    }
    for (auto& sprites : Mapletrees)
    {
        sprites.draw(window);
    }
    for (auto& sprites : bonetrees)
    {
        sprites.draw(window);
    }
        window.display();
    }
    return 0;
}
