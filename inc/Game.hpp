#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <Ball.hpp>
#include <Board.hpp>
#include <thread>
#include <chrono>
namespace LE {
	class Game {
	private:
		sf::RenderWindow* m_window = nullptr; //Окно
		std::string m_caption; // Название
		Point m_Field; // Границы
		sf::Clock m_timer; // Таймер для скорости
	public:
		Game();
		void SetResolution(Point field);
		void SetCaption(std::string caption);
		void Setup();
		void Run(Point field,Point balls,int RadiusBalls,int speed);
	};
}