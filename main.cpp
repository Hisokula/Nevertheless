#include <SFML/Graphics.hpp>
#include "Func.hpp"
#include "Map.hpp"
#include "View.hpp"


int DimensionScreenX = 1920;
int DimensionScreenY = 1080;

sf::Vector2f SpritePosition(0, 0);
sf::Vector2f PositionOnScreen(0, 0);

int RobertDimensionX = 256;
int RobertDimensionY = 256;

sf::View view;

namespace espv
{
    sf::View GetPlayerCoordForView(float x, float y)
    {
        view.setCenter(x, y);
        return view;
    }
}


int main()
{
    //рендер виндова + установка ограничения на фпс
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Nevertheless works!");
    window.setFramerateLimit(120);

    view.reset(sf::FloatRect(0, 0, 1920, 1080));


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


    sf::View view(sf::FloatRect(0, 0, DimensionScreenX, DimensionScreenY));



    //клок клок
    sf::Clock clock;

    sf::RectangleShape rectangle(sf::Vector2f(150, 150)); //борюсь с картой, это к ней относится

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

        //разберись с скроллом
        sf::FloatRect rect;
        rect = sf::FloatRect(0, 0, 256, 256);

        
        //window.setView(view);
        PositionOnScreen.x = Robert.getPosition().x + RobertDimensionX - (DimensionScreenX / 2);
        PositionOnScreen.y = Robert.getPosition().y + RobertDimensionY - (DimensionScreenY / 2);

        SpritePosition.x = Robert.getPosition().x;
        SpritePosition.y = Robert.getPosition().y;

        if ((SpritePosition.x <= 0) && (SpritePosition.y <= 0))
            Robert.setPosition(0, 0);
        else if (SpritePosition.x <= 0)
            Robert.setPosition(0, SpritePosition.y);
        else if (SpritePosition.y <= 0)
            Robert.setPosition(SpritePosition.x, 0);



        if (PositionOnScreen.x < 0)
            PositionOnScreen.x = 0;
        if (PositionOnScreen.y < 0)
            PositionOnScreen.y = 0;
        
        view.reset(sf::FloatRect(PositionOnScreen.x, PositionOnScreen.y, DimensionScreenX, DimensionScreenY));

        //черный выглядел стильно, но это тоже ничего
        window.clear(sf::Color::White);

        //BOX
        sf::Texture box_texture;
        box_texture.loadFromFile("box.png");
        sf::Sprite Box;
        Box.setTexture(box_texture);
        Box.setTextureRect(sf::IntRect(0, 0, 140, 130));


        bool boxflag = 0;
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
                    Box.setPosition(j * 150 + 10, i * 150 + 20);/////////// спрайт ящика!!!!!!!!
                    window.draw(Box);
                    boxflag = 1;
                
                }
                if (TileMap[i][j] == 'P')
                {
                    rectangle.setFillColor(sf::Color::Red);
                }

                if (TileMap[i][j] == ' ') continue;

                if (boxflag == 0)
                {
                    rectangle.setPosition(j * 150, i * 150);
                    window.draw(rectangle);
                }
                boxflag = 0;

            }
        }


        //я создала рабочий класс, swag
        //ура, пролетариат
        esp::PlayerRobert PLAYER(&Robert, &robert_texture, &rev_robert_texture);
        PLAYER.Controls(&robert_texture, &rev_robert_texture, &CurrentFrame, &time);
        PLAYER.CoordUpd(&time);

        //view.setCenter(PLAYER.GetPlayerCoordX(), PLAYER.GetPlayerCoordY());

        //самое вкусное
        window.setView(view);
        window.draw(Robert);
        window.display();

        


    }


}