#include <SFML/Graphics.hpp>
#include "Func.hpp"


int main()
{
    //рендер виндова + установка ограничения на фпс
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Nevertheless works!");
    window.setFramerateLimit(120);


    //с этим я пока сама не разобралась
    //возможно, это будет картой :D
    const int H = 12;
    const int W = 40;

    sf::String TileMap[H] =
    {
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
        "B                                      B",
        "B                                      B",
        "B                                      B",
        "B                                      B",
        "B                                      B",
        "B                                      B",
        "BBBB                                   B",
        "B  BB                                  B",
        "B   BB                                 B",
        "BP  XBB                                B",
        "BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
    };

    //сет текстур для Роберта(основной и реверснутой)
    sf::Texture robert_texture;
    robert_texture.loadFromFile("roberto.png");

    sf::Texture rev_robert_texture;
    rev_robert_texture.loadFromFile("robertorev.png");

    //создание спрайта Роберта
    //желательно запихнуть в класс
    sf::Sprite Robert;
    Robert.setTexture(robert_texture);
    Robert.setPosition(960, 540);
    Robert.setTextureRect(sf::IntRect(0, 0, 256, 256));

    //клок клок
    sf::Clock clock;

    sf::RectangleShape rectangle; //борюсь с картой, это к ней относится

    //это важно это надо
    float CurrentFrame = 0;

    //время для виндова
    while (window.isOpen())
    {
        //тут понятно, снова клок клок
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();

        //дабы не создать вечный двигатель
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //черный выглядел стильно, но это тоже ничего
        window.clear(sf::Color::White);

        
        //всё ещё борьба с ТаЙлМаПоМ
        for (int i = 0; i < H; i++)
        {
            for (int j = 0; j < W; j++)
            {
                if (TileMap[i][j] == 'B')
                {
                    rectangle.setFillColor(sf::Color::Black);
                }
                if (TileMap[i][j] == 'X')
                {
                    rectangle.setFillColor(sf::Color::Magenta);
                }
                if (TileMap[i][j] == 'P')
                {
                    rectangle.setFillColor(sf::Color::Red);
                }
                if (TileMap[i][j] == ' ') continue;

                rectangle.setPosition(j * 32, i * 32);
                window.draw(rectangle);
            }
        }

        //самое вкусное
        window.draw(Robert);
        window.display();

        //я создала рабочий класс, swag
        //ура, пролетариат
        esp::PlayerRobert PLAYER(&Robert, &robert_texture, &rev_robert_texture);
        PLAYER.Controls(&robert_texture, &rev_robert_texture, &CurrentFrame, &time);
        


    }


}