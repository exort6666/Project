#include <Game.hpp>
namespace LE {
	Game::Game() {
	}
	void Game::SetResolution(Point field) {
		m_Field = field;
	}
	void Game::SetCaption(std::string caption) {
		m_caption = caption;
	}
	void Game::Setup() {
		m_window = new sf::RenderWindow(sf::VideoMode(m_Field.x, m_Field.y), m_caption);
	}
	void Game::Run(Point field, Point balls, int RadiusBalls, int speed) 
	{
		//Создаю задний фон
		sf::Texture background;
		background.loadFromFile("R.png");
		sf::Sprite backgrounds(background);

		//Создаю шарик
		std::vector<LE::Ball*> ball;
		ball.emplace_back(new LE::Ball({ 400,430 }, { 80,-80 }));
		ball[0]->Setup();

		//Создаю доску
		std::vector<LE::Board*> board;
		board.emplace_back(new LE::Board({ 375,480 }));
		board[0]->Setup();
		
		//Создаю вектор для квадратов
		std::vector<sf::Sprite> wall;

		// Создаю одну текстуру для всех квадратов
		sf::Texture squares;
		squares.loadFromFile("square.png");

		
		// Создаю вектор,который хранит коробки для хранения хитбоксов спрайтов
		std::vector<sf::FloatRect> boundingBox;
		while (balls.y <= 200) { // Создаю квадраты
			while (field.x >= balls.x + RadiusBalls) {
				sf::Sprite square(squares);
				square.setScale(0.5, 0.5);
				square.setPosition(balls.x - RadiusBalls, balls.y - RadiusBalls);
				wall.push_back(square);
				boundingBox.push_back(square.getGlobalBounds());
				balls.x += 2 * RadiusBalls;
			}
			balls.y += 2 * RadiusBalls;
			balls.x = RadiusBalls;
		}
		
		bool flag = false;
		m_timer.restart();
		while (m_window->isOpen()) {
			//запускаю окно
			sf::Event event;
			while (m_window->pollEvent(event)) {
				if (event.type == sf::Event::Closed)
					m_window->close();
				if (event.type == sf::Event::KeyPressed)
					flag = true;
			}

			// Получаю текущую позицию шарика
			Point p = ball[0]->GetPosition();
			
			// Если шарик выходит за рамки сверху или сбоку,
			// то меняем направление скорости шарика
			if (p.y <= 0) {
				Vec v = ball[0]->GetSpeed();
				ball[0]->SetSpeed({ v.x,-v.y });
			}
			if (p.x + ball[0]->GetRadX() >= m_Field.x) {
				Vec v = ball[0]->GetSpeed();
				ball[0]->SetSpeed({ -v.x,v.y });
			}
			if (p.x <= 0) {
				Vec v = ball[0]->GetSpeed();
				ball[0]->SetSpeed({ -v.x,v.y });
			}
			//Каждый раз обнуляя таймер высчитаю передвижение
			sf::Time dt = m_timer.restart();
			if (flag == true)
				ball[0]->Move(dt.asSeconds());
			
			//Добавляю доске передвижение на стрелочки и на AD
			board[0]->moveOfBoard();

			m_window->clear();
			//Создаю задний фон,шарик,доску,квадраты
			m_window->draw(backgrounds);
			m_window->draw(ball[0]->getSprite());
			m_window->draw(board[0]->getSprite());
			for (size_t i = 0; i < wall.size(); i++) {
				m_window->draw(wall[i]);
			}


			m_window->display();

			// Проверяю на взаимодействие спрайтов,
			// если шарик и квадрат пересекается, то квадрат
			// выносится за рамки игрового поля
			// а шарик меняет направление
			// если шарик и доска пересекаются, то с доской
			// ничего не происходит
			// а шарик меняет направление
			sf::FloatRect Ballbox = ball[0]->GetRect();
			sf::FloatRect Boardbox = board[0]->GetRect();
			long long t = 0;
			for (size_t i = 0; i < boundingBox.size(); i++) {
				if (Ballbox.intersects(boundingBox[i]))
				{
					if (t % 2 == 0) {
						Vec v = ball[0]->GetSpeed();
						ball[0]->SetSpeed({ v.x,-v.y });
					}
					t += 1;
					boundingBox.erase(boundingBox.begin() + i);
					wall.erase(wall.begin() + i);
					break;
				}
			}
			t = 0;
			if (Ballbox.intersects(Boardbox)) {
				if (t % 2 == 0) {
					Vec v = ball[0]->GetSpeed();
					ball[0]->SetSpeed({ v.x,-v.y });
				}
				t += 1;
			}
			
			// Делаю меньше кадров,что бы проц не грузило
			std::this_thread::sleep_for(std::chrono::milliseconds(30));
		}
	}
}