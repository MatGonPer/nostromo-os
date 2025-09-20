#include <SFML/Graphics.hpp>

int main() {
    sf::Window window(sf::VideoMode({800, 600}), "Nostromo OS", sf::Style::None, sf::State::Fullscreen);
    window.setVerticalSyncEnabled(true);

    while(window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if(event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

    }

    return 0;
}