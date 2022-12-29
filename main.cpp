#include <SFML/Graphics.hpp>
#include "Func.hpp"
#include "Map.hpp"


int DimensionScreenX = 1920;
int DimensionScreenY = 1080;

sf::Vector2f SpritePosition(0, 0);
sf::Vector2f PositionOnScreen(0, 0);

int RobertDimensionX = 256;
int RobertDimensionY = 256;

sf::View view;


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

    //BOX
    sf::Texture box_texture;
    box_texture.loadFromFile("box.png");
    sf::Sprite Box;
    Box.setTexture(box_texture);
    Box.setTextureRect(sf::IntRect(0, 0, 140, 130));
    Box.setPosition(800, 1526);


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

            if (event.type == sf::Event::MouseWheelMoved)
            {
                if (event.mouseWheel.delta == -1)
                    view.setSize(DimensionScreenX += 10, DimensionScreenY += 10);
                if (event.mouseWheel.delta == 1)
                    view.setSize(DimensionScreenX -= 10, DimensionScreenY -= 10);
            }
        }

        //разберись с скроллом
        sf::FloatRect rect;
        rect = sf::FloatRect(0, 0, 256, 256);


        //window.setView(view);
        PositionOnScreen.x = Robert.getPosition().x + RobertDimensionX - (DimensionScreenX / 2);
        PositionOnScreen.y = Robert.getPosition().y + RobertDimensionY - (DimensionScreenY / 2);

        SpritePosition.x = Robert.getPosition().x;
        SpritePosition.y = Robert.getPosition().y;

        int Wt = 40;
        int Ht = 12;

        if ((SpritePosition.x <= 0) && (SpritePosition.y <= 0))
            Robert.setPosition(0, 0);

        else if (SpritePosition.x <= 0)
            Robert.setPosition(0, SpritePosition.y);

        else if (SpritePosition.y <= 0)
            Robert.setPosition(SpritePosition.x, 0);

        else if (SpritePosition.x >= Wt * 150)
            Robert.setPosition(Wt * 150, SpritePosition.y);

        else if (SpritePosition.y >= Ht * 150)
            Robert.setPosition(SpritePosition.x, Ht * 150);

        else if ((SpritePosition.x >= Wt * 150) && (SpritePosition.y >= Ht * 150))
            Robert.setPosition(Wt * 150, Ht * 150);



        if (PositionOnScreen.x < 0)
            PositionOnScreen.x = 0;
        if (PositionOnScreen.y < 0)
            PositionOnScreen.y = 0;

        view.reset(sf::FloatRect(PositionOnScreen.x, PositionOnScreen.y, DimensionScreenX, DimensionScreenY));

        //
        window.clear(sf::Color::White);



        sf::Texture boxboxbox;
        boxboxbox.loadFromFile("boxboxbox.png");

        sf::FloatRect Rect;

        sf::Vector2f BoxPosition(0, 0);

        bool boxflag = 0;

        for (int i = 0; i < H + 10; i++)
        {
            for (int j = 0; j < W + 10; j++)
            {
                if ((i >= H) || (j >= W))
                {
                    rectangle.setPosition(i * 150, j * 150);
                    rectangle.setFillColor(sf::Color::Black);
                }
                else
                {
                    if (TileMap[i][j] == 'B')
                    {
                        rectangle.setFillColor(sf::Color::Black);
                    }
                    if (TileMap[i][j] == 'T')
                    {
                        rectangle.setFillColor(sf::Color::Cyan);
                    }
                    if (TileMap[i][j] == 'X')
                    {
                        boxflag = 1;

                        BoxPosition.x = j * 150 + 10;
                        BoxPosition.y = i * 150 + 20;
                    }
                    if (TileMap[i][j] == 'P')
                    {
                        rectangle.setFillColor(sf::Color::Red);
                        //Rect = rectangle;
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
        }


        //я создала рабочий класс, swag
        //ура, пролетариат
        esp::PlayerRobert PLAYER(&Robert, &robert_texture, &rev_robert_texture);
        PLAYER.Controls(&robert_texture, &rev_robert_texture, &CurrentFrame, &time);
        PLAYER.CoordUpd(&time);

        esp::Box BOX(&Box, &box_texture);

        BOX.SetBoxCoordX(BoxPosition.x);
        BOX.SetBoxCoordY(BoxPosition.y);


        sf::FloatRect RobertBounds = Robert.getGlobalBounds();
        sf::FloatRect BoxBounds = Box.getGlobalBounds();

        if (RobertBounds.intersects(BoxBounds))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                BOX.SetPossession(1);
            }
        }


       /* if ((abs(SpritePosition.x - BoxPosition.x) <= 100) || (abs(SpritePosition.y - BoxPosition.y) <= 100))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                BOX.SetPossession(1);
            }

        */

        /*sf::Texture empty;
        empty.loadFromFile("empty.png")*/


        if (BOX.GetPossession() == 1)
        {
            Robert.setTexture(boxboxbox);
            Box.setTextureRect(sf::IntRect(200, 200, 201, 201));
            Box.setPosition(Robert.getPosition().x, Robert.getPosition().y);

            if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
            {
                BOX.SetPossession(0);
                Box.setTextureRect(sf::IntRect(0, 0, 140, 130));
            }

        }
        std::cout << "R" << Robert.getPosition().x << " " << Robert.getPosition().y << std::endl;
        std::cout << "B" << Box.getPosition().x << " " << Box.getPosition().y << std::endl;

        //PLAYER.InsideTheBox(BOX.GetPossession(), &Box, &Robert);

        //view.setCenter(PLAYER.GetPlayerCoordX(), PLAYER.GetPlayerCoordY());

        //самое вкусное
        window.setView(view);
        window.draw(Box);
        window.draw(Robert);
        window.display();




    }


}