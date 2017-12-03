#ifndef BLOCK_HPP
#define BLOCK_HPP

#include "drawable.hpp"
#include <SFML/Graphics.hpp>

class block : public drawable {
  private:
    sf::RectangleShape rectangle;

  public:
    block(sf::Vector2f position, sf::Vector2f size);
    void draw(sf::RenderWindow &window) const;
    void updatePosition();
    sf::FloatRect getBounds() const;
    void jump(sf::Vector2f target);
};

#endif // BLOCK_HPP
