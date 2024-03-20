#include "Button.h"

Button::Button() : Button("0"){}

Button::Button(const std::string &text) : Button(text, 10.f) {}

Button::Button(const std::string &text, float radius)
: Button (text, radius, Fonts::getFont(OPEN_SANS)) {}


Button::Button(const std::string &text, float radius, sf::Font& font)
: defaultColor(80,80,80), clickColor(212,212,210) {
    setUpCircle(radius);
    setUpText(text, font);
}

void Button::setUpText(const std::string &text, sf::Font &font) {
    this->text.setFont(font);
    this->text.setString(text);
    setCharacterSize();
    Position::centerText(circle, this->text);
}

void Button::setUpCircle(float radius) {
    circle.setRadius(radius);
    circle.setFillColor(defaultColor);
}

void Button::setCharacterSize() {
    unsigned int size = (2.f/3) * (2 * circle.getRadius());
    this->text.setCharacterSize(size);
}

void Button::update() {
    if (getState(CLICKED)) {
        circle.setFillColor(clickColor);
    } else {
        circle.setFillColor(defaultColor);
    }
}


void Button::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if(!getState(HIDDEN)) {
        states.transform = circle.getTransform();
        window.draw(circle);
        window.draw(text, states);
    }
}

void Button::setRadius(float radius) {
    circle.setRadius(radius);
    setCharacterSize();
    Position::centerText(circle, text);
}

void Button::setFont(const sf::Font &font) {
    text.setFont(font);
}

void Button::setText(const std::string &text) {
    this->text.setString(text);
    Position::centerText(circle, this-> text);
}

std::string Button::getText() {
    return text.getString();
}

void Button::setClickColor(sf::Color color) {
    clickColor = color;
}

void Button::setDefaultColor(sf::Color color) {
    defaultColor = color;
}

void Button::setPosition(sf::Vector2f position) {
    circle.setPosition(position);
}

void Button::eventHandler(sf::RenderWindow &window, sf::Event event) {
    if (MouseEvents::isClicked(circle, window)) {
        enableState(CLICKED);
    } else {
        disableState(CLICKED);
    }
}

sf::FloatRect Button::getGlobalBounds() const {
    return circle.getGlobalBounds();
}