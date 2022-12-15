#include<iostream>
#include"Func.hpp"
#include <SFML/Graphics.hpp>

namespace esp
{
	void Controls(sf::Sprite Robert, float* CurrentFrame, float* time)
	{
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            {
                Robert.move(-0.2 * (*time) / 225, 0);
                *CurrentFrame += 0.05;
                if (*CurrentFrame > 5)
                    *CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(*CurrentFrame) + 256, 0, -256, 256));
            }
            else
            {
                Robert.move(-0.1 * (*time) / 300, 0);
                *CurrentFrame += 0.03;
                if (*CurrentFrame > 5)
                    *CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(*CurrentFrame) + 256, 0, -256, 256));
            }

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            {
                Robert.move(0.2 * (*time) / 225, 0);
                *CurrentFrame += 0.05;
                if (*CurrentFrame > 5)
                    *CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(*CurrentFrame), 0, 256, 256));
            }
            else
            {
                Robert.move(0.1 * (*time) / 300, 0);
                *CurrentFrame += 0.03;
                if (*CurrentFrame > 5)
                    *CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(*CurrentFrame), 0, 256, 256));
            }


        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            {
                Robert.move(0, -0.2 * (*time) / 225);
                *CurrentFrame += 0.05;
                if (*CurrentFrame > 5)
                    *CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(*CurrentFrame), 0, 256, 256));
            }
            else
            {
                Robert.move(0, -0.1 * (*time) / 300);
                *CurrentFrame += 0.03;
                if (*CurrentFrame > 5)
                    *CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(*CurrentFrame), 0, 256, 256));
            }



        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
            {
                Robert.move(0, 0.2 * (*time) / 225);
                *CurrentFrame += 0.05;
                if (*CurrentFrame > 5)
                    *CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(*CurrentFrame), 0, 256, 256));
            }

            else
            {
                Robert.move(0, 0.1 * (*time) / 300);
                *CurrentFrame += 0.03;
                if (*CurrentFrame > 5)
                    *CurrentFrame -= 5;
                Robert.setTextureRect(sf::IntRect(256 * int(*CurrentFrame), 0, 256, 256));
            }



        }
	}
    
	
	
}