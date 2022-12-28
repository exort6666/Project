#include <Board.hpp>
namespace LE
{
	Board::Board(Point p0) { //� ������������ ���������
		//�������������� ������
		m_p0 = p0;
	}
	bool Board::Setup() { //������������ �������� � ������ ������
		m_texture = new sf::Texture;
		if (!m_texture->loadFromFile("board.png")) {
			return false;
		}
		m_sprite = new sf::Sprite;
		m_sprite->setTexture(*m_texture);
		float scale_x = 1;
		float scale_y = 1;
		m_sprite->setScale(scale_x, scale_y);
		m_sprite->setPosition(m_p0.x, m_p0.y);
	}
	sf::Sprite Board::getSprite() {//��������� ������
		return (*m_sprite);
	}
	Board::~Board() {//� ����������� ��������� ������ � ��������
		if (m_sprite != nullptr)
			delete m_sprite;
		if (m_texture != nullptr)
			delete m_texture;
	}
	sf::FloatRect Board::GetRect() { //��������� �������
		return(getSprite().getGlobalBounds());
	}
	void Board::moveOfBoard() //�������� ���������� � ����������
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))m_sprite->setPosition(m_sprite->getPosition() + sf::Vector2f(-4, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))m_sprite->setPosition(m_sprite->getPosition() + sf::Vector2f(4, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))m_sprite->setPosition(m_sprite->getPosition() + sf::Vector2f(-4, 0));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))m_sprite->setPosition(m_sprite->getPosition() + sf::Vector2f(4, 0));
	}
}