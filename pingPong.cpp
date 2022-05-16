#include <iostream>
#include <SFML/Graphics.hpp>

int player1Score = 0;
int player2Score = 0;

bool intersect(sf::CircleShape& c1, sf::RectangleShape& rect2)
{
    sf::FloatRect circle = c1.getGlobalBounds();
    sf::FloatRect rectangle = rect2.getGlobalBounds();
    return circle.intersects(rectangle);
}

int main()
{
    sf::VideoMode videomode(400,400);
    sf::RenderWindow window(videomode, "PONG");
    sf::CircleShape Ball;
    Ball.setFillColor(sf::Color::Black);
    Ball.setRadius(10);
    Ball.setPosition(100,200);
    sf::RectangleShape firsPlayer;
    firsPlayer.setFillColor(sf::Color::Green);
    firsPlayer.setSize(sf::Vector2f(10,50));
    firsPlayer.setPosition(30,200);

    sf::RectangleShape secondPlayer;
    secondPlayer.setFillColor(sf::Color::Green);
    secondPlayer.setSize(sf::Vector2f(10,50));
    secondPlayer.setPosition(370, 200);

    sf::RectangleShape outleft;
    outleft.setFillColor(sf::Color::Black);
    outleft.setSize(sf::Vector2f(10,400));
    outleft.setPosition(390,0);

    sf::RectangleShape outright;
    outright.setFillColor(sf::Color::Black);
    outright.setSize(sf::Vector2f(10,400));
    outright.setPosition(0,0);

    sf::RectangleShape mid;
    mid.setFillColor(sf::Color::Red);
    mid.setSize(sf::Vector2f(20,400));
    mid.setPosition(200,0);

    sf::RectangleShape up;
    up.setFillColor(sf::Color::Red);
    up.setSize(sf::Vector2f(20,400));
    up.setPosition(400,0);
    up.rotate(90);

    sf::RectangleShape down;
    down.setFillColor(sf::Color::Red);
    down.setSize(sf::Vector2f(20,400));
    down.setPosition(400,380);
    down.rotate(90);
    sf::RectangleShape left;
    sf::RectangleShape right;
    sf::Vector2<float>ballSpeed(0.1,0.1);

    while(window.isOpen())
    {
        window.clear(sf::Color::Blue);
        window.draw(mid);
        window.draw(Ball);
        window.draw(secondPlayer);
        window.draw(down);
        window.draw(up);
        window.draw(firsPlayer);
        window.draw(outleft);
        window.draw(outright);
        window.display();

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            firsPlayer.move(0,-0.1);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            firsPlayer.move(0,0.1);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            secondPlayer.move(0,-0.1);
        }
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            secondPlayer.move(0,0.1);
        }
        
        if(intersect(Ball,outleft))
        {
            player1Score++;
            Ball.setPosition(100,200);
            std::cout<<"Player1score: "<<player1Score<<std::endl;
        }
        else if(intersect(Ball,outright))
        {
            player2Score++;
            Ball.setPosition(100,200);
            std::cout<<"Player2score: "<<player2Score<<std::endl;
        }

        if(intersect(Ball,up)||(intersect(Ball,down)))
        {
            ballSpeed.y = -ballSpeed.y;
        }
        
        if(intersect(Ball,firsPlayer)||(intersect(Ball,secondPlayer)))
        {
            ballSpeed.x = -ballSpeed.x;
        }
        Ball.move(ballSpeed.x,ballSpeed.y);
    }


}
