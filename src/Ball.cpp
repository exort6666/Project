#include <Ball.hpp>
namespace LE {
	Ball::Ball(Point p0, Vec speed) { 
		//� ������������ ��������� ��������� � �������� ������
		m_p0 = p0;
		m_speed = speed;
	}
	bool Ball::Setup() { //������������ �������� � ������ ������
		m_texture = new sf::Texture;
		if (!m_texture->loadFromFile("shape1.png")) {
			return false;
		}
		m_sprite = new sf::Sprite;
		m_sprite->setTexture(*m_texture);
		float scale_x = 0.5;
		float scale_y = 0.5;
		m_r.x = m_texture->getSize().x * scale_x;
		m_r.y = m_texture->getSize().y * scale_y;
		m_sprite->setScale(scale_x, scale_y);
		m_sprite->setPosition(m_p0.x, m_p0.y);
	}
	sf::Sprite Ball::getSprite() { //������ ������� 
		return (*m_sprite);
	}
	Ball::~Ball() { //� ����������� ������ ������� � ��������
		if (m_sprite != nullptr)
			delete m_sprite;
		if (m_texture != nullptr)
			delete m_texture;
	}
	void Ball::Move(double dt) {// ������� ��� ����������� ������
		m_p0.x += m_speed.x * dt;
		m_p0.y += m_speed.y * dt;

		m_sprite->setPosition(m_p0.x, m_p0.y);
	}
	Point Ball::GetPosition() { // ������������ ������� ������
		return m_p0;
	}
	Vec Ball::GetSpeed() {  // ������� ��� ��������� ��������
		return m_speed;
	}
	void Ball::SetSpeed(Vec speed) { //������� ��� ������ ��������,
		//� ������ ������ �� ���������������
		m_speed = speed;
	}
	float Ball::GetRadX() { 
		//������� ��� ��������� ������� ������� �� x
		return (m_r.x);
	}
	float Ball::GetRadY() {
		//������� ��� ��������� ������� ������� �� y
		return (m_r.y);
	}
	sf::FloatRect Ball::GetRect() { // ������� ��� ��������� ��������
		return(getSprite().getGlobalBounds());
	}
}