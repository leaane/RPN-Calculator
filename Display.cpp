#include "Display.h"

Display::Display(sf::Vector2f size, sf::Font &font, unsigned int characterSize, sf::Color color, sf::Vector2f position,
                 int limit) {
    setSize(size);
    setFont(font);
    setCharacterSize(characterSize);
    setColor(color);
    setPosition(position);
    setCharacterLimit(limit);
}

Display::Display()
: Display({200,100}, Fonts::getFont(ARIAL), 24, sf::Color::White,{20,25},9)
{}

Display::Display(sf::Vector2f size, sf::Font &font, unsigned int characterSize)
: Display(size, font, characterSize, sf::Color::Black, {0,0}, 9)
{

}

void Display::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    if (!getState(HIDDEN)) {
        window.draw(box);
        window.draw(text);
    }
}

void Display::show() {
    disableState(HIDDEN);
}

void Display::clear() {
    text.setString("");
}

void Display::setText(const std::string &text) {
    this->text.setString(text);
    this->text.setFillColor(sf::Color::Black);
    Position::centerText(box, this->text);
}

std::string Display::getText() {
    return text.getString();
}

void Display::setCharacterLimit(int limit) {
    this->limit = limit;
}

void Display::setColor(sf::Color color) {
    box.setFillColor(color);
}

void Display::setFont(const sf::Font &font) {
    text.setFont(font);
}

void Display::setSize(sf::Vector2f size) {
    box.setSize(size);
}

void Display::setPosition(sf::Vector2f position) {
    box.setPosition(position);
    //TODO center text with position class
}

void Display::setCharacterSize(unsigned int size) {
    text.setCharacterSize(size);
}