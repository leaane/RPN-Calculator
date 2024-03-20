#ifndef CS3A_MOUSEEVENTS_H
#define CS3A_MOUSEEVENTS_H

#include <SFML/Graphics.hpp>

namespace MouseEvents {
    template<typename T>
    bool isHovered(const T& obj, sf::RenderWindow& window);
    template<typename T>
    bool isClicked(const T& obj, sf::RenderWindow& window);


} //MouseEvents

#include "MouseEvents.cpp"
#endif //CS3A_MOUSEEVENTS_H
