#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
namespace LE {
	struct Point {
		float x;
		float y;
	};
	struct Vec {
		float x;
		float y;
	};
	class Ball {
	private:
		Point m_p0;//Местоположение шарика
		Vec m_speed;// Скорость шарика
		sf::Texture* m_texture = nullptr; //Указатель текстры шарика
		sf::Sprite* m_sprite = nullptr;//Указатель спрайта шарика
		Point m_r; // Радиус Шарика
	public:
		Ball(Point p0, Vec speed);
		bool Setup();
		sf::Sprite getSprite();
		~Ball();
		void Move(double dt);
		Point GetPosition();
		Vec GetSpeed();
		void SetSpeed(Vec speed);
		float GetRadX();
		float GetRadY();
		sf::FloatRect GetRect();
	};
}