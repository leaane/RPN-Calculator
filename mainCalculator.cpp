///rpn reverse polish notation
/// 34+ == 7
/// 234^+ == 3^4+2=83
/// 34*25*+ == 12+10=22
/// 342+*5* == 3*6*5=90

#include "Calculator.h"

int main () {
    sf::VideoMode videoMode(320, 420, 32);
    sf::RenderWindow window(videoMode,"Calculator");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    Calculator calc;

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            calc.eventHandler(window, event);
        }

        calc.update();
        window.clear();
        window.draw(calc);
        window.display();

    }

    return 0;
}