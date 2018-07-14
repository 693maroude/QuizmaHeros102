#include <sstream>
#include "DEFINITIONS.hpp"
#include "player.hpp"
#include "Games.hpp"
#include "GameState.hpp"
#include <SFML/Window.hpp>

#include <iostream>
#include<string>
#include<fstream>

namespace Quizma
{
	player::player(GameDataRef data) : _data(data)
	{
	}
	void player::Init()
	{
		this->_data->assets.LoadTexture("Player Background", PLAYER_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Player Background"));
		
	}
	void player::HandleInput()
	{
		sf::Event event;
		std::string name;
		std::ofstream playerFile;
		playerFile.open("highcore.txt");
		while (this->_data->window.pollEvent(event))
		{
			if (sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Return)
				{
					this->_data->sound.setBuffer(this->_data->buffer);
					this->_data->sound.play();
					this->_data->machine.AddState(StateRef(new GameState(_data)), true);
				}
				if (event.type == sf::Event::TextEntered) 
				{
					if (event.text.unicode >= 33 && event.text.unicode <= 126)
						name += (char)event.text.unicode;
					else if (event.text.unicode == 8)
						name = name.substr(0, name.length() - 1);
					system("cls");
					std::cout << name;
					playerFile << name << ":";
					playerFile.close();
				}
			}
		}
	}
	void player::Update(float dt)
	{
	}
	void player::Draw(float dt)
	{
		this->_data->window.clear();
		this->_data->window.draw(this->_data->text);
		this->_data->window.clear(sf::Color::Black);
		this->_data->window.draw(this->_background);
		this->_data->window.draw(this->_border);
		this->_data->window.display();
	}
}