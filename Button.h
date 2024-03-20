#ifndef CS3A_BUTTON_H
#define CS3A_BUTTON_H

#include <SFML/Graphics.hpp>
#include "Position.h"
#include "Fonts.h"
#include "MouseEvents.h"
#include "States.h"

class Button : public sf::Drawable, public States {
private:
    sf::Text text;
    sf::CircleShape circle;
    sf::Color defaultColor, clickColor;
    void setUpText(const std::string& text, sf::Font& font);
    void setUpCircle(float radius);
    void setCharacterSize();

public:
    Button();
    Button(const std::string& text);
    Button(const std::string& text, float radius);
    Button(const std::string& text, float radius, sf::Font& font);
    virtual void draw(sf::RenderTarget& window, sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void setRadius(float radius);
    void setFont(const sf::Font& font);
    void setText(const std::string& text);
    std::string getText();
    void setClickColor(sf::Color color);
    void setDefaultColor(sf:: Color color);
    void setPosition(sf::Vector2f position);
    void update();
    sf::FloatRect getGlobalBounds() const;

};


#endif //CS3A_BUTTON_H
