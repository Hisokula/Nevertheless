#include<iostream>
#include"Func.hpp"
#include <SFML/Graphics.hpp>

namespace esp
{
    //оказываетс€, класс нужно объ€вл€ть в заголовочном файле, поэтому что будет здесь € без пон€ти€


    /*class PlayerRobert
    {
    private:
        sf::Sprite m_Robert;
        sf::Texture m_robert_texture;
        sf::Texture m_rev_robert_texture;
    public:
        PlayerRobert(sf::Sprite Robert, sf::Texture robert_texture, sf::Texture rev_robert_texture)
        {
            m_Robert = Robert;
            m_robert_texture = robert_texture;
            m_rev_robert_texture = rev_robert_texture;
        }

        void Controls(sf::Sprite* Robert, sf::Texture* robert_texture, sf::Texture* rev_robert_texture, float* CurrentFrame, float* time)
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            {
                (*Robert).setTexture(*rev_robert_texture);
                (*Robert).setTextureRect(sf::IntRect(0, 0, 256, 256));

                if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                {
                    (*Robert).move(-0.2 * (*time) / 225, 0);
                    (*CurrentFrame) += 0.05;
                    if ((*CurrentFrame) > 5)
                        ((*CurrentFrame)) -= 5;
                    (*Robert).setTextureRect(sf::IntRect(256 * int((*CurrentFrame)), 0, 256, 256));
                }
                else
                {
                    (*Robert).move(-0.1 * (*time) / 300, 0);
                    (*CurrentFrame) += 0.03;
                    if ((*CurrentFrame) > 5)
                        (*CurrentFrame) -= 5;
                    (*Robert).setTextureRect(sf::IntRect(256 * int((*CurrentFrame)), 0, 256, 256));
                }

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            {
                (*Robert).setTexture(*robert_texture);
                (*Robert).setTextureRect(sf::IntRect(0, 0, 256, 256));
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                {
                    (*Robert).move(0.2 * (*time) / 225, 0);
                    (*CurrentFrame) += 0.05;
                    if ((*CurrentFrame) > 5)
                        (*CurrentFrame) -= 5;
                    (*Robert).setTextureRect(sf::IntRect(256 * int((*CurrentFrame)), 0, 256, 256));
                }
                else
                {
                    (*Robert).move(0.1 * (*time) / 300, 0);
                    (*CurrentFrame) += 0.03;
                    if ((*CurrentFrame) > 5)
                        (*CurrentFrame) -= 5;
                    (*Robert).setTextureRect(sf::IntRect(256 * int((*CurrentFrame)), 0, 256, 256));
                }


            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                {
                    (*Robert).move(0, -0.2 * (*time) / 225);
                    (*CurrentFrame) += 0.05;
                    if ((*CurrentFrame) > 5)
                        (*CurrentFrame) -= 5;
                    (*Robert).setTextureRect(sf::IntRect(256 * int((*CurrentFrame)), 0, 256, 256));
                }
                else
                {
                    (*Robert).move(0, -0.1 * (*time) / 300);
                    (*CurrentFrame) += 0.03;
                    if ((*CurrentFrame) > 5)
                        (*CurrentFrame) -= 5;
                    (*Robert).setTextureRect(sf::IntRect(256 * int((*CurrentFrame)), 0, 256, 256));
                }

            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) || sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::RShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
                {
                    (*Robert).move(0, 0.2 * (*time) / 225);
                    (*CurrentFrame) += 0.05;
                    if ((*CurrentFrame) > 5)
                        (*CurrentFrame) -= 5;
                    (*Robert).setTextureRect(sf::IntRect(256 * int((*CurrentFrame)), 0, 256, 256));
                }

                else
                {
                    (*Robert).move(0, 0.1 * (*time) / 300);
                    (*CurrentFrame) += 0.03;
                    if ((*CurrentFrame) > 5)
                        (*CurrentFrame) -= 5;
                    (*Robert).setTextureRect(sf::IntRect(256 * int((*CurrentFrame)), 0, 256, 256));
                }

            }
        }

    };
    */
	
	
}