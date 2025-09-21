#pragma once

#include <SFML/Graphics.hpp>

class Terminal {
private:
    //Fonte VCR_OSD_MONO_1
    sf::Font font_;
    //Cor para o texto do terminal
    sf::Color retro_green_;
    //Cor para o terminal em si
    sf::Color dark_green_;
    //Texto título do terminal Nostromo OS
    sf::Text title_text_;
public:
    Terminal();
    void handle_event(const sf::Event& event);
    void update();
    void render(sf::RenderWindow& window);
};