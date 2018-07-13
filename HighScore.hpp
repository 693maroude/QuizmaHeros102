#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include "State.hpp"
#include "Games.hpp"

namespace Quizma
{
	class HighScore : public State
	{
	public:
		HighScore(GameDataRef data);

		void Init();

		void HandleInput();
		void Update(float dt);
		void Draw(float dt);

	private:
		GameDataRef _data;

		sf::Sprite _background;
		sf::Sprite _questionBox;
		sf::Sprite _optionsBox1;
		sf::Sprite _optionsBox2;
		sf::Sprite _optionsBox3;
		sf::Sprite _optionsBox4;
		sf::Sprite _playAgain;
		sf::Sprite _Quit;
	};
}
