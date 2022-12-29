#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


namespace esp
{

    class Box;
	

    class PlayerRobert
    {
    private:
        sf::Sprite* m_Robert;
        sf::Texture* m_robert_texture;
        sf::Texture* m_rev_robert_texture;

        float PlayerCoordX = 960;
        float PlayerCoordY = 540;

    public:

        int m_direction = 0;
        float m_speed = 0;
        float m_dx = 0;
        float m_dy = 0;

        PlayerRobert(sf::Sprite* Robert, sf::Texture* robert_texture, sf::Texture* rev_robert_texture)
        {
            m_Robert = Robert;
            m_robert_texture = robert_texture;
            m_rev_robert_texture = rev_robert_texture;
        }


        void CoordUpd(float* time)
        {
            PlayerCoordX += m_dx * (*time);
            PlayerCoordY += m_dy * (*time);

            m_dx = 0;
            m_dy = 0;

        }


        float GetPlayerCoordX()
        {
            return PlayerCoordX;
        }

        float GetPlayerCoordY()
        {
            return PlayerCoordY;
        }

        void Controls(sf::Texture* robert_texture, sf::Texture* rev_robert_texture, float* CurrentFrame, float* time)
        {
            sf::Sprite* Robert = m_Robert;
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

    class Box
    {
    private:
        sf::Sprite* m_Box;
        sf::Texture* m_box_texture;

        float BoxCoordX = 0;
        float BoxCoordY = 0;

        bool possession = 0;

    public:

        Box(sf::Sprite* box, sf::Texture* box_texture)
        {
            m_Box = box;
            m_box_texture = box_texture;
        }

        void SetBoxCoordX(float x)
        {
            BoxCoordX = x;
        }

        void SetBoxCoordY(float y)
        {
            BoxCoordY = y;
        }

        void SetPossession(bool p)
        {
            possession = p;
        }

        bool GetPossession()
        {
            return possession;
        }
        void Fall(float* time)
        {

            if ((possession == 0) && (BoxCoordY <= 1800))
            {
                sf::Sprite* Box = m_Box;

            }
            
            
        }


    };

}