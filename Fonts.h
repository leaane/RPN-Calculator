#ifndef CS3A_FONTS_H
#define CS3A_FONTS_H

#include <SFML/Graphics.hpp>
#include <map>
#include "FontEnum.h"

class Fonts {
private:
    inline static std::map<FontEnum, sf::Font> fonts;
    static std::string getPath(FontEnum font);
    static void loadFont(FontEnum font);

public:
    static sf::Font& getFont(FontEnum font);
};


#endif //CS3A_FONTS_H
