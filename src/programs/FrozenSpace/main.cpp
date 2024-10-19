#include <SFML/Graphics.hpp>
#include <iostream>
#include <imgui.h>
#include "imgui-SFML.h"

sf::RenderWindow window;
sf::Texture texture;

int main()
{
    window.create(sf::VideoMode(1920, 1080), "FrozenSpace");
    window.setFramerateLimit(60);
    ImGui::SFML::Init(window);

    sf::Clock clock;

    if (!texture.loadFromFile("resources/tiles/land.png"))
    {
        std::cout << "Load Error";
    }

    sf::Sprite image;
    image.setTexture(texture);
    image.setPosition(sf::Vector2f(-200, -200));
    image.scale(sf::Vector2f(1.5f, 1.5f));

    bool pushed = false;

    sf::Vector2f mouseOldPos;
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float dt = elapsed.asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            ImGui::SFML::ProcessEvent(window, event);

            if (event.type == sf::Event::MouseButtonPressed)
            {
                pushed = true;
                mouseOldPos.x = 0;
                mouseOldPos.y = 0;
            }

            if (event.type == sf::Event::MouseButtonReleased)
            {
                pushed = false;
            }

            if (pushed && event.type == sf::Event::MouseMoved)
            {
               sf::Event::MouseMoveEvent moveEvent = event.mouseMove;
               sf::Vector2f mouseNewPos(moveEvent.x, moveEvent.y);
               if (mouseOldPos.x != 0 && mouseOldPos.y != 0)
               {
                   sf::Vector2f delta = mouseNewPos - mouseOldPos;
                   image.setPosition(image.getPosition() + delta);
               }
               mouseOldPos = mouseNewPos;
            }



            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();
        } 

        
        ImGui::SFML::Update(window, elapsed);
        ImGui::Begin("Window");
        ImGui::Button("Look at this pretty button");
        ImGui::End();
        

        window.clear(sf::Color::Black);
        window.draw(image);
        ImGui::SFML::Render(window);
        window.display();
    }

    ImGui::SFML::Shutdown();

    return 0;
}