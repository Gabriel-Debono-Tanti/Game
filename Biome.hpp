#pragma once


#include <iostream>
#include <SFML/Graphics.hpp>

class Biome
{
private:
    
public:
    sf::RectangleShape biome;
    Biome(sf::Vector2f size, sf::Color colour){
        biome.setSize(size);
        biome.setFillColor(colour);
    }
    void drawTo(sf::RenderWindow &window){
        window.draw(biome);
    }
    sf::FloatRect getglobalbounds(){
        return biome.getGlobalBounds();
    }
    void setPos(sf::Vector2f pos){
        biome.setPosition(pos);
    }
    int id;
};



