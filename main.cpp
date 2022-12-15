﻿#include <SFML/Graphics.hpp>
#include "Func.hpp"

//#include "Source.cpp"

int main()
{

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Nevertheless works!");
    window.setFramerateLimit(120);

    sf::Texture robert_texture;
    robert_texture.loadFromFile("roberto.png");

    sf::Sprite Robert;
    Robert.setTexture(robert_texture);
    Robert.setPosition(960, 540);
    Robert.setTextureRect(sf::IntRect(0, 0, 256, 256));

    sf::Clock clock;

    float CurrentFrame = 0;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(Robert);
        window.display();

        esp::Controls(Robert, &CurrentFrame, &time);//не работает, тащи обратно в main
    }


}