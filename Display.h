#ifndef CS3A_DISPLAY_H
#define CS3A_DISPLAY_H

#include <SFML/Graphics.hpp>
#include "Fonts.h"
#include "States.h"
#include "Position.h"

class Display : public sf::Drawable, public States {
private:
    Display(sf::Vector2f size, sf::Font& font, unsigned int characterSize, sf::Color color, sf::Vector2f position, int limit);
    sf::Text text;
    sf::RectangleShape box;
    int limit;

public:
    Display();
    Display(sf::Vector2f size, sf::Font& font, unsigned int characterSize);
    virtual void draw(sf::RenderTarget& window , sf::RenderStates states) const;
    void show();
    void clear();
    void setText(const std::string& text);
    std::string getText();
    void setCharacterLimit(int limit);
    void setColor(sf::Color color);
    void setFont(const sf::Font& font);
    void setSize(sf::Vector2f size);
    void setPosition(sf::Vector2f position);
    void setCharacterSize(unsigned int size);

};


#endif //CS3A_DISPLAY_H
