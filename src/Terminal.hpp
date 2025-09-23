#pragma once

#include <SFML/Graphics.hpp>

class Terminal {
private:
    //Fonte VCR_OSD_MONO_1
    sf::Font font_;
    //Cor para o texto do terminal
    const sf::Color retro_green_;
    //Cor para o terminal em si
    const sf::Color dark_green_;
    //Texto título do terminal Nostromo OS
    sf::Text title_text_;
    //Guarda o que o usuário digita
    std::string input_string_;
    //Para o "> "
    sf::Text prompt_text_;
    //Para desenhar o input_string_
    sf::Text input_text_;
    //Para o "_"
    sf::RectangleShape cursor_;
    //O Cronômetro do cursor
    sf::Clock cursor_clock_;
    //Estado do cursor (visivel/invisivel)
    bool cursor_visible_;
public:
    Terminal();
    void handle_event(const sf::Event& event);
    void update();
    void render(sf::RenderWindow& window);
};