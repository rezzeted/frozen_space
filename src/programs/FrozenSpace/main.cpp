#include <SFML/Graphics.hpp>

sf::RenderWindow window;

int main()
{
    window.create(sf::VideoMode(800, 600), "City Builder");
    window.setFramerateLimit(60);

    sf::Clock clock;

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        window.clear(sf::Color::Black);
        window.display();

        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        }

    }

    return 0;
}