#ifndef PICTURE_HPP
#define PICTURE_HPP

#include "drawable.hpp"
#include <SFML/Graphics.hpp>
#include <string>

class picture : public drawable {
  private:
    sf::Sprite pic;
    sf::Texture tex;
    std::string filename;

  public:
    picture(sf::Vector2f position, std::string filename);
    void draw(sf::RenderWindow &window) const;
    void move(sf::Vector2f target);
    sf::FloatRect getBounds() const;
    void write(std::ofstream &output);
};

#endif // PICTURE_HPP
