


#include <iostream>
#include "SFML/Graphics.hpp"

class Object
{
public:
    Object(const sf::Texture& texture, const sf::Vector2f& position, int health)
        : m_obj(texture),
          m_health(health)
    {
        m_obj.setPosition(position);
        m_obj.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);
    }

    void draw(sf::RenderWindow& window)
    {
        window.draw(m_obj);
    }

    bool isAlive() const
    {
        return m_health > 0;
    }

    void takeDamage(int damage)
    {
        m_health -= damage;
    }
    
    bool contains(const sf::Vector2f& point) const {
        sf::FloatRect bounds = m_obj.getGlobalBounds();
        return bounds.contains(sf::Vector2f(point));
    }

    const sf::Vector2f& getPosition() const
    {
        return m_obj.getPosition();
    }

    float getRadius() const
    {
        return m_obj.getGlobalBounds().width / 2.f;
    }

public:
    sf::Sprite m_obj;
    int m_health;
};






