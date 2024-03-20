#include "Calculator.h"

Calculator::Calculator() {
    background.setSize({320,420});
    background.setFillColor(sf::Color(48, 47, 46));
    display.setSize({280,90});
    display.setColor(sf::Color::White);
    equation = "";
    calculated = false;
    setButtons();
}

void Calculator::draw(sf::RenderTarget &window, sf::RenderStates states) const {
    window.draw(background);
    window.draw(display);
    for (const auto & button : buttons) {
            window.draw(button);
        }
}

void Calculator::eventHandler(sf::RenderWindow &window, sf::Event event) {
    for (auto & button : buttons) {
        button.eventHandler(window, event);
    }

    std::string num = getEquation(window);

    if (num == "x") {
        equation = "";
    } else if (num == "=") {
        equation = std::to_string(RPN::evaluate(equation));
        calculated = true;
    } else {
        equation += num;
    }
    setDisplayText(equation);
}


void Calculator::update() {
    for (auto & button : buttons) {
            button.update();
    }
}

void Calculator::setDisplayText(const std::string &text) {
   display.setText(text);
}

std::string Calculator::getEquation(sf::RenderWindow& window) {


    for (int i = 0; i < buttons.size(); i++) {
        if (MouseEvents::isClicked(buttons[i], window)) {
            if (calculated) {
                equation = "";
                calculated = false;
            }

            if (i < 10) {
                return std::to_string(i);
            } else {
                switch (i) {
                    case 10: return "+";
                    case 11: return "*";
                    case 12: return "/";
                    case 13: return "-";
                    case 14: return "x";
                    case 15: return "=";
                }
            }
        }
    }
  return "";
}

void Calculator::setButtons() {
    //First Row
    Button seven("7", 30);
    seven.setPosition({10,140});

    Button eight("8", 30);
    eight.setPosition({90,140});

    Button nine("9", 30);
    nine.setPosition({170,140});

    Button multiply("x", 30);
    multiply.setPosition({250,140});
    multiply.setDefaultColor(sf::Color(209, 131, 42));

    //Second Row
    Button four("4", 30);
    four.setPosition({10,210});

    Button five("5", 30);
    five.setPosition({90,210});

    Button six("6", 30);
    six.setPosition({170,210});

    Button divide("/", 30);
    divide.setPosition({250,210});
    divide.setDefaultColor(sf::Color(209, 131, 42));

    //Third Row
    Button one("1", 30);
    one.setPosition({10,280});

    Button two("2", 30);
    two.setPosition({90,280});

    Button three("3", 30);
    three.setPosition({170,280});

    Button plus("+", 30);
    plus.setPosition({250,280});
    plus.setDefaultColor(sf::Color(209, 131, 42));

    //Fourth row
    Button zero("0", 30);
    zero.setPosition({10,350});

    Button deletes("C", 30);
    deletes.setPosition({90,350});

    Button equal("=", 30);
    equal.setPosition({170,350});
    equal.setDefaultColor(sf::Color(209, 131, 42));

    Button minus("-", 30);
    minus.setPosition({250,350});
    minus.setDefaultColor(sf::Color(209, 131, 42));


    buttons.push_back(zero);
    buttons.push_back(one);
    buttons.push_back(two);
    buttons.push_back(three);
    buttons.push_back(four);
    buttons.push_back(five);
    buttons.push_back(six);
    buttons.push_back(seven);
    buttons.push_back(eight);
    buttons.push_back(nine);
    buttons.push_back(plus);
    buttons.push_back(multiply);
    buttons.push_back(divide);
    buttons.push_back(minus);
    buttons.push_back(deletes);
    buttons.push_back(equal);
}