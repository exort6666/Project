#pragma once
#include <Ball.hpp>
#include <Game.hpp>
namespace LE //Создание именного пространства
{
	class Board //Создание класса 
	{
	public:
		Board(){

		}
		sf::RectangleShape board;

		void moveOfBoard()
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) board.setPosition(board.getPosition() + sf::Vector2f(-0.80, 0));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) board.setPosition(board.getPosition() + sf::Vector2f(0.80, 0));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) board.setPosition(board.getPosition() + sf::Vector2f(-0.80, 0));
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) board.setPosition(board.getPosition() + sf::Vector2f(0.80, 0));
		}
	};
}