#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "drawable.hpp"
#include <SFML/Graphics.hpp>

class circle : public drawable {
  private:
    sf::CircleShape c;

  public:
    circle(sf::Vector2f position, sf::Color color, float size = 15.0);
    void draw(sf::RenderWindow &window) const;
    void move(sf::Vector2f target);
    sf::FloatRect getBounds() const;
    void write(std::ofstream &output);
};

#endif // CIRCLE_HPP
