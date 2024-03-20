#include "Background.h"

Background::Background() :Background({100, 200}) {

}

Background::Background(sf::Vector2f size) : sf::RectangleShape(size), States() {

}

void Background::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents::isHovered(*this, window)) {
        enableState(HOVERED);
    } else {
        disableState(HOVERED);
    }
}

void Background::update() {
    hover();
}

void Background::hover() {
    if (getState(HOVERED)) {
        setFillColor(sf::Color::Blue);
    } else {
        setFillColor(sf::Color::White);
    }
}