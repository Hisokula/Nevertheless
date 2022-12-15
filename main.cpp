#include <SFML/Graphics.hpp>
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

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            {
                Robert.move(-0.2 * time / 225, 0);
                CurrentFrame += 0.05;
                if (CurrentFrame > 5)
                    CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(CurrentFrame) + 256, 0, -256, 256));
            }
            else
            {
                Robert.move(-0.1 * time / 300, 0);
                CurrentFrame += 0.03;
                if (CurrentFrame > 5)
                    CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(CurrentFrame) + 256, 0, -256, 256));
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            {
                Robert.move(0.2 * time / 225, 0);
                CurrentFrame += 0.05;
                if (CurrentFrame > 5)
                    CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(CurrentFrame), 0, 256, 256));
            }
            else
            {
                Robert.move(0.1 * time / 300, 0);
                CurrentFrame += 0.03;
                if (CurrentFrame > 5)
                    CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(CurrentFrame), 0, 256, 256));
            }


        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            {
                Robert.move(0, -0.2 * time / 225);
                CurrentFrame += 0.05;
                if (CurrentFrame > 5)
                    CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(CurrentFrame), 0, 256, 256));
            }
            else
            {
                Robert.move(0, -0.1 * time / 300);
                CurrentFrame += 0.03;
                if (CurrentFrame > 5)
                    CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(CurrentFrame), 0, 256, 256));
            }



        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            {
                Robert.move(0, 0.2 * time / 225);
                CurrentFrame += 0.05;
                if (CurrentFrame > 5)
                    CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(CurrentFrame), 0, 256, 256));
            }

            else
            {
                Robert.move(0, 0.1 * time / 300);
                CurrentFrame += 0.03;
                if (CurrentFrame > 5)
                    CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(CurrentFrame), 0, 256, 256));
            }



        }
        //esp::Controls(Robert, &CurrentFrame, &time);//не работает, тащи обратно в main
    }


}