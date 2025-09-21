#include "Terminal.hpp"
#include <iostream>

Terminal::Terminal() : retro_green_(50, 255, 50), dark_green_(5, 15, 5), title_text_(font_) {
    if (!font_.openFromFile("../assets/fonts/VCR_OSD_MONO_1.001.ttf")) {
        std::cout << "ERRO: ao importar fonte!\nNão foi possível encontrar a fonte em assets/fonts/VCR_OSD_MONO_1.001.tff\nEncerrando o programa..." << std::endl;
    } else {
        std::cout << "Fonte importada com sucesso!" << std::endl;
    }

    //Carrega fonte, define a string, o tamanho, a cor e o estilo
    title_text_.setFont(font_);
    title_text_.setString("Nostromo OS");
    title_text_.setCharacterSize(28);
    title_text_.setFillColor(retro_green_);
    title_text_.setStyle(sf::Text::Regular);

    sf::FloatRect text_rectangle = title_text_.getLocalBounds();
    title_text_.setOrigin({text_rectangle.position.x + text_rectangle.size.x / 2.0f, text_rectangle.position.y + text_rectangle.size.y / 2.0f});
}

void Terminal::render(sf::RenderWindow& window) {
    //Limpar a tela com a cor de fundo do terminal
    window.clear(dark_green_);
    //Posicionar e desenhar o texto
    title_text_.setPosition({window.getSize().x / 2.0f, (window.getSize().y - 450) - 2.0f});
    window.draw(title_text_);
}

void Terminal::handle_event(const sf::Event& event) {

}

void Terminal::update() {

}