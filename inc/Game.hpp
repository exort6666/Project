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
		sf::RenderWindow* m_window = nullptr; //����
		std::string m_caption; // ��������
		Point m_Field; // �������
		sf::Clock m_timer; // ������ ��� ��������
	public:
		Game();
		void SetResolution(Point field);
		void SetCaption(std::string caption);
		void Setup();
		void Run(Point field,Point balls,int RadiusBalls,int speed);
	};
}