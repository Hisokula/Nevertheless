#pragma once
#include <SFML/Graphics.hpp>

namespace esp
{
	
	void Controls(sf::Sprite Robert, float* CurrentFrame, float* time);


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