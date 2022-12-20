#pragma once
#include <SFML/Graphics.hpp>

namespace esp
{
	
	//void Controls(sf::Sprite* Robert, sf::Texture* robert_texture, sf::Texture* rev_robert_texture, float* CurrentFrame, float* time);

    //он прекрасен(Controls не в счёт, просто не открывайте)
    class PlayerRobert
    {
    private:
        sf::Sprite* m_Robert;
        sf::Texture* m_robert_texture;
        sf::Texture* m_rev_robert_texture;
    public:
        PlayerRobert(sf::Sprite* Robert, sf::Texture* robert_texture, sf::Texture* rev_robert_texture)
        {
            m_Robert = Robert;
            m_robert_texture = robert_texture;
            m_rev_robert_texture = rev_robert_texture;
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


}
/*
class Robert
	{
	private:
		// x_coord, y_coord -- координаты левого верхнего угла прямоугльника, в который заключёе спрайт
		float m_x_coord = 0;
		float m_y_coord = 0;

		// x_side_size, y_side_size -- стороны(соответственно ширина и высота)
		float m_x_side_size = 0;
		float m_y_side_size = 0;

		// x_position, y_position -- координаты начальной позиции Роберта
		float m_x_position = 0;
		float m_y_position = 0;


		void RobertOnScreen()
		{
			// звгрузка и задание текстуры спрайту Роберта
			sf::Texture robert_texture;
			robert_texture.loadFromFile("robert.png");

			sf::Sprite RobertSprite;
			RobertSprite.setTexture(robert_texture);

			// задание начальной позиции Роберта и текстуры по прямоугольнику
			RobertSprite.setPosition(m_x_position, m_y_position);
			RobertSprite.setTextureRect(sf::IntRect(m_x_coord, m_y_coord, m_x_side_size, m_y_side_size));
		}

	public:

		Robert(float x_coord, float y_coord, float x_side_size, float y_side_size, float x_position, float y_position);

		void Robert::AddPlayer()
		{

		}



	};

	void Controls();
*/