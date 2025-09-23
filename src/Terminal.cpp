#include "Terminal.hpp"
#include <iostream>

Terminal::Terminal() : retro_green_(50, 255, 50), dark_green_(5, 15, 5), title_text_(font_), input_string_(""), prompt_text_(font_), input_text_(font_), cursor_() {
    if (!font_.openFromFile("../assets/fonts/VCR_OSD_MONO_1.001.ttf")) {
        std::cout << "ERRO: ao importar fonte!\nNão foi possível encontrar a fonte em assets/fonts/VCR_OSD_MONO_1.001.tff\nEncerrando o programa..." << std::endl;
    } else {
        std::cout << "Fonte importada com sucesso!" << std::endl;
    }

    const unsigned int CHARACTER_TITLE_SIZE = 31;
    const unsigned int CHARACTER_TEXT_SIZE = 18;

    //Carrega fonte, define a string, o tamanho, a cor e o estilo
    title_text_.setFont(font_);
    title_text_.setString("Nostromo OS");
    title_text_.setCharacterSize(CHARACTER_TITLE_SIZE);
    title_text_.setFillColor(retro_green_);
    title_text_.setStyle(sf::Text::Regular);

    //Input do que o usuário digita
    prompt_text_.setFont(font_);
    prompt_text_.setString("> ");
    prompt_text_.setCharacterSize(CHARACTER_TEXT_SIZE);
    prompt_text_.setFillColor(retro_green_);
    prompt_text_.setStyle(sf::Text::Regular);

    input_text_.setFont(font_);
    input_text_.setString(input_string_);
    input_text_.setCharacterSize(CHARACTER_TEXT_SIZE);
    input_text_.setFillColor(retro_green_);
    input_text_.setStyle(sf::Text::Regular);

    //Cursor retangular analógico
    cursor_.setSize({CHARACTER_TEXT_SIZE * 0.6f, CHARACTER_TEXT_SIZE});
    cursor_.setFillColor(retro_green_);
    cursor_visible_ = true;

    //Posição do título Nostromo OS
    sf::FloatRect text_rectangle = title_text_.getLocalBounds();
    title_text_.setOrigin({text_rectangle.position.x + text_rectangle.size.x / 2.0f, text_rectangle.position.y + text_rectangle.size.y / 2.0f});
}

void Terminal::render(sf::RenderWindow& window) {
    //Limpar a tela com a cor de fundo do terminal
    window.clear(dark_green_);

    //Posicionar o título "Nostromo OS" 
    title_text_.setPosition({window.getSize().x / 2.0f, (window.getSize().y - 450) - 2.0f});
    //Desenha o title_text_ "Nostromo OS" na tela
    window.draw(title_text_);

    //Posiciona o cursor "> "
    prompt_text_.setPosition({(window.getSize().x / 2.0f) - 300, (window.getSize().y / 2.0f) + 200});
    //Posiciona o que o usuário digita
    sf::Vector2f prompt_end_pos = prompt_text_.findCharacterPos(prompt_text_.getString().getSize());
    input_text_.setPosition(prompt_end_pos);
    //Posiciona o cursor
    sf::Vector2f input_end_pos = input_text_.findCharacterPos(input_string_.size());
    cursor_.setPosition(input_end_pos);
    //Desenha o prompt_text_ "> " na tela
    window.draw(prompt_text_);
    //Desenha o que o usuário digita
    window.draw(input_text_);
    //Desenha o cursor se vísivel
    if (cursor_visible_) {
        window.draw(cursor_);
    }
}

void Terminal::handle_event(const sf::Event& event) {
    if(const auto* text_entered = event.getIf<sf::Event::TextEntered>()) {
        if(text_entered->unicode < 128 && text_entered->unicode != 8) {
            input_string_.push_back(static_cast<char>(text_entered->unicode));
            input_text_.setString(input_string_);
        }
    } else if (const auto* text_event = event.getIf<sf::Event::KeyPressed>()) {
        switch(text_event->code) {
            case sf::Keyboard::Key::Backspace:
                if (!input_string_.empty()) {
                    input_string_.pop_back();
                    input_text_.setString(input_string_);
                }
                break;
            case sf::Keyboard::Key::Enter:
                input_string_.clear();
                input_text_.setString(input_string_);
                break;
            default:
                break;
        }
    }
}

void Terminal::update() {
    const float blink_interval_seconds = 0.53f;

    if (cursor_clock_.getElapsedTime().asSeconds() > blink_interval_seconds) {
        cursor_visible_ = !cursor_visible_;
        cursor_clock_.restart();
    }
}