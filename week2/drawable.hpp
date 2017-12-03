#ifndef DRAWABLE_HPP
#define DRAWABLE_HPP

#include <SFML/Graphics.hpp>
class drawable {
public:
  virtual void draw(sf::RenderWindow &window) const = 0;
  virtual void updatePosition() = 0;
  virtual sf::FloatRect getBounds() const = 0;
};

#endif // DRAWABLE_HPP
