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
		sf::RenderWindow* m_window = nullptr;
		std::string m_caption;
		Point m_Field;
		sf::Clock m_timer;
	public:
		Game(){
		}
		void SetResolution(Point field) {
			m_Field = field;
		}
		void SetCaption(std::string caption) {
			m_caption = caption;
		}
		void Setup() {
			m_window = new sf::RenderWindow(sf::VideoMode(m_Field.x, m_Field.y), m_caption);
		}
		void Run(Point field,Point balls,int RadiusBalls,int speed) {
			std::vector<LE::Ball*> ball;
			sf::Texture background;//ќбъ€вление объекта текстуры
			background.loadFromFile("R.png");//‘он берЄм из файла
			sf::Sprite backgrounds(background);
			ball.emplace_back(new LE::Ball({ 250,460 }, { 80,-80 }));
			ball[0]->Setup();
			std::vector< sf::Sprite> wall;
			sf::Texture squares;
			squares.loadFromFile("square.png");
			while (balls.y <= 200) { //  вадраты
				while (field.x >= balls.x + RadiusBalls) {
					sf::Sprite square(squares);
					square.setScale(0.5, 0.5);
					square.setPosition(balls.x - RadiusBalls, balls.y - RadiusBalls);
					wall.push_back(square);
					balls.x += 2 * RadiusBalls;
				}
				balls.y += 2 * RadiusBalls;
				balls.x = RadiusBalls;
			}
			LE::Board doska;
			doska.board.setSize(sf::Vector2f(60, 10));
			doska.board.setPosition(230, 480);
			doska.board.setFillColor(sf::Color::Yellow);
			m_timer.restart();
			while (m_window->isOpen()) {
				sf::Event event;
				while (m_window->pollEvent(event)) {
					if (event.type == sf::Event::Closed)
						m_window->close();
				}
				Point p = ball[0]->GetPosition();
				if (p.y> m_Field.y) {
					Vec v = ball[0]->GetSpeed();
					ball[0]->SetSpeed({ v.x,-v.y });
				}
				if (p.y<= 0) {
					Vec v = ball[0]->GetSpeed();
					ball[0]->SetSpeed({ v.x,-v.y });
				}
				if (p.x > m_Field.x) {
					Vec v = ball[0]->GetSpeed();
					ball[0]->SetSpeed({ -v.x,v.y });
				}
				if (p.x < 0) {
					Vec v = ball[0]->GetSpeed();
					ball[0]->SetSpeed({ -v.x,v.y });
				}
				sf::Time dt = m_timer.restart();
				ball[0]->Move(dt.asSeconds());
				m_window->clear();
				doska.moveOfBoard(); 
				m_window->draw(backgrounds);
				balls.x = RadiusBalls;
				balls.y = RadiusBalls;
				m_window->draw(doska.board);// доска
				for (size_t i = 0; i < wall.size(); i++) {
					m_window->draw(wall[i]);
				}
				m_window->draw(ball[0]->getSprite());
				m_window->display();
				std::this_thread::sleep_for(std::chrono::milliseconds(30));
			}
		}
	};
}