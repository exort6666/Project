#include <Game.hpp>
#include <Ball.hpp>
#include <MoveBall.hpp>
#include <Board.hpp>
void main()
{
    LE::Point Field = { 800, 500 }; // Создаю границы
    int RadiusBalls = 25;
    int Speed = 10;
    LE::Point Balls = { RadiusBalls,RadiusBalls };
    std::cout << Balls.x << " " << Balls.y << std::endl;
    LE::Game game;
    game.SetResolution(Field);
    game.SetCaption("Test");
    game.Setup();
    game.Run(Field, Balls, RadiusBalls,Speed);
}