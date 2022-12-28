#pragma once
#include <Game.hpp>
namespace LE 
{
	class Board 
	{
		struct Point {
			int x;
			int y;
		};
	private:
		sf::Sprite* m_sprite=nullptr;// ”казатель спрайта доски
		sf::Texture* m_texture =nullptr;// ”казатель спрайта текстуры
		Point m_p0; // ћестоположение доски
	public:
		Board(Point p0);
		bool Setup();
		sf::Sprite getSprite();
		~Board();
		sf::FloatRect GetRect();
		void moveOfBoard();
	};
}