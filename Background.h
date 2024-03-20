#ifndef CS3A_BACKGROUND_H
#define CS3A_BACKGROUND_H

#include <SFML/Graphics.hpp>
#include "States.h"
#include "MouseEvents.h"

class Background : public sf::RectangleShape, public States {
private:
    void hover();
public:
    Background();
    Background(sf::Vector2f size);
    void eventHandler(sf::RenderWindow& window, sf::Event event);
    void update();
};


#endif //CS3A_BACKGROUND_H
