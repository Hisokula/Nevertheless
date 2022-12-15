#include <SFML/Graphics.hpp>

int main()
{

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Nevertheless works!");
    window.setFramerateLimit(120);

    sf::CircleShape MyCircle(128.f);
    MyCircle.setFillColor(sf::Color::Cyan);

    sf::Texture t;
    t.loadFromFile("robert.png");

    sf::Sprite Robert;
    Robert.setTexture(t);
    Robert.setPosition(960, 540);
    Robert.setTextureRect(sf::IntRect(0, 0, 328, 328));

    sf::Clock clock;

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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                Robert.move(-0.2 * time / 225, 0);
            else
                Robert.move(-0.1 * time / 300, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                Robert.move(0.2 * time / 225, 0);
            else
                Robert.move(0.1 * time / 300, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                Robert.move(0, -0.2 * time / 225);
            else
                Robert.move(0, -0.1 * time / 300);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                Robert.move(0, 0.2 * time / 225);
            else
                Robert.move(0, 0.1 * time / 300);
        }
    }


}