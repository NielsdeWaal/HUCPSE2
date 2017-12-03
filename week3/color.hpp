#ifndef COLOR_HPP
#define COLOR_HPP

const struct {
    const char *name;
    sf::Color color;
} colors[]{{"yellow", sf::Color::Yellow}, {"red", sf::Color::Red},
           {"blue", sf::Color::Blue},     {"green", sf::Color::Green},
           {"black", sf::Color::Black},   {"cyan", sf::Color::Cyan},
           {"white", sf::Color::White},   {"magenta", sf::Color::Magenta}};

#endif // COLOR_HPP
