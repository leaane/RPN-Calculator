#ifndef CS3A_CALCULATOR_H
#define CS3A_CALCULATOR_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Background.h"
#include "Button.h"
#include "Display.h"
#include "RPN.h"

class Calculator : public sf::Drawable {
private:
    Background background;
    Display display;
    std::vector<Button> buttons;
    std::string equation;
    void setButtons();
    bool calculated;

public:
    Calculator();
    virtual void draw(sf::RenderTarget& window , sf::RenderStates states) const;
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void setDisplayText(const std::string &text);
    std::string getEquation(sf::RenderWindow& window);
    void update();
};


#endif //CS3A_CALCULATOR_H