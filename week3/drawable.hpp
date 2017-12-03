#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
class drawable {
  public:
    virtual void draw(sf::RenderWindow &window) const = 0;
    virtual sf::FloatRect getBounds() const = 0;
    virtual void move(sf::Vector2f target) = 0;
    virtual void write(std::ofstream &output) = 0;
};

#endif // DRAWABLE_HPP
