#pragma once

#include <SFML/Graphics.hpp>
#include "Terminal.hpp"

class Application {
private:
    sf::RenderWindow window_;
    Terminal terminal_;
    void process_events();
    void update();
    void render();
public:
    Application();
    void run();
};