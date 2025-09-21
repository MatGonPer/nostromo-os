#include "Application.hpp"

Application::Application() : window_(sf::VideoMode({640, 480}), "Nostromo OS", sf::Style::None, sf::State::Windowed) {
    const sf::VideoMode desktop_mode = sf::VideoMode::getDesktopMode();
    const int x_position = (desktop_mode.size.x - window_.getSize().x) / 2;
    const int y_position = (desktop_mode.size.y - window_.getSize().y) / 2;
    window_.setPosition({x_position, y_position});

    window_.setVerticalSyncEnabled(true);
}

//Método principal de Execução
void Application::run() {
    while (window_.isOpen()) {
        process_events();
        update();
        render();
    }
}

void Application::process_events() {
    while (const std::optional event = window_.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window_.close();
        }

        terminal_.handle_event(*event);
    }
}

void Application::update() {
    terminal_.update();
}

void Application::render() {
    terminal_.render(window_);
    window_.display();
}