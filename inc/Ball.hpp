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
		Point m_p0;
		Vec m_speed;
		sf::Texture* m_texture = nullptr;
		sf::Sprite* m_sprite = nullptr;
	public:
		Ball(Point p0, Vec speed) {
			m_p0 = p0;
			m_speed = speed;
		}
		bool Setup() {
			m_texture = new sf::Texture;
			if (!m_texture->loadFromFile("shape.png")) {
				return false;
			}
			m_sprite = new sf::Sprite;
			m_sprite->setTexture(*m_texture);
			float scale_x = 0.4;
			float scale_y = 0.4;
			float x = m_texture->getSize().x;
			float y = m_texture->getSize().y;
			m_sprite->setScale(scale_x, scale_y);
		}
		sf::Sprite getSprite() {
			return (*m_sprite);
		}
		~Ball(){
			if (m_sprite != nullptr)
				delete m_sprite;
			if (m_texture != nullptr)
				delete m_texture;
		}
		void Move(double dt) {
			m_p0.x += m_speed.x * dt;
			m_p0.y += m_speed.y * dt;

			m_sprite->setPosition(m_p0.x, m_p0.y);
		}
		Point GetPosition() {
			return m_p0;
		}
		Vec GetSpeed() {
			return m_speed;
		}
		void SetSpeed(Vec speed) {
			m_sprite->setRotation(90);
			m_speed = speed;
		}
	};
}