#include "Fonts.h"

std::string Fonts::getPath(FontEnum font) {
    switch(font) {
        case OPEN_SANS: return "Fonts/OpenSans-Bold.ttf";
        case ARIAL: return "Fonts/arial.ttf";
    }
}

void Fonts::loadFont(FontEnum font) {
    fonts[font].loadFromFile(getPath(font));
}

sf::Font &Fonts::getFont(FontEnum font) {
    loadFont(font);
    return fonts[font];
}