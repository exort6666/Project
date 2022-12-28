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
		Point m_p0;//�������������� ������
		Vec m_speed;// �������� ������
		sf::Texture* m_texture = nullptr; //��������� ������� ������
		sf::Sprite* m_sprite = nullptr;//��������� ������� ������
		Point m_r; // ������ ������
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