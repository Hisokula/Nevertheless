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

    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Nevertheless works!");
    window.setFramerateLimit(120);

    view.reset(sf::FloatRect(0, 0, 1920, 1080));



    sf::Texture robert_texture;
    robert_texture.loadFromFile("roberto.png");

    sf::Texture rev_robert_texture;
    rev_robert_texture.loadFromFile("robertorev.png");


    sf::Sprite Robert;
    Robert.setTexture(robert_texture);
    Robert.setPosition(960, 540);
    Robert.setTextureRect(sf::IntRect(0, 0, 256, 256));


    sf::Texture box_texture;
    box_texture.loadFromFile("box.png");
    sf::Sprite Box;
    Box.setTexture(box_texture);
    Box.setTextureRect(sf::IntRect(0, 0, 140, 130));
    Box.setPosition(800, 1526);


    sf::View view(sf::FloatRect(0, 0, DimensionScreenX, DimensionScreenY));


    sf::Clock clock;

    sf::RectangleShape rectangle(sf::Vector2f(150, 150));


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

            if (event.type == sf::Event::MouseWheelMoved)
            {
                if (event.mouseWheel.delta == -1)
                    view.setSize(DimensionScreenX += 10, DimensionScreenY += 10);
                if (event.mouseWheel.delta == 1)
                    view.setSize(DimensionScreenX -= 10, DimensionScreenY -= 10);
            }
        }


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


        window.clear(sf::Color::White);



        sf::Texture boxboxbox;
        boxboxbox.loadFromFile("boxboxbox.png");


        sf::Vector2f BoxPosition(0, 0);

        sf::Sprite RedPusher;



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
                        RedPusher.setPosition(i * 150, j * 150);

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

        sf::FloatRect RedPusherBounds = RedPusher.getGlobalBounds();

        if (BoxBounds.intersects(RedPusherBounds))
        {
            sf::Text text;
            sf::Font font;
            //font.loadFromFile();
            //text.setFont(font);

            text.setString("Hello world");
            text.setCharacterSize(100);
            text.setFillColor(sf::Color::Red);
            window.draw(text);
        }

        std::cout << "R" << RedPusher.getPosition().x << " " << RedPusher.getPosition().y << std::endl;
        std::cout << "B" << Box.getPosition().x << " " << Box.getPosition().y << std::endl;

        //BOX.Fall(&time);




        window.setView(view);
        window.draw(Box);
        window.draw(Robert);
        window.display();




    }


}