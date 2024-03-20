cmake_minimum_required(VERSION 3.24)
project(RPN_Calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(RPN_Calculator
        Background.cpp
        Background.h
        Button.cpp
        Button.h
        Calculator.cpp
        Calculator.h
        Display.cpp
        Display.h
        Fonts.cpp
        Fonts.h
        mainCalculator.cpp
        RPN.cpp
        RPN.h
        States.h
        States.cpp
        StatesEnum.h)

target_link_libraries(RPN_Calculator sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)