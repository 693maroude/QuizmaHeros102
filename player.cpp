#include <sstream>
#include "DEFINITIONS.hpp"
#include "player.hpp"
#include "Games.hpp"
#include "GameState.hpp"
#include <SFML/Window.hpp>

#include <iostream>

namespace Quizma
{
	player::player(GameDataRef data) : _data(data)
	{
	}
	void player::Init()
	{
		this->_data->assets.LoadTexture("Player Background", PLAYER_BACKGROUND_FILEPATH);
		_background.setTexture(this->_data->assets.GetTexture("Player Background"));

		this->_data->assets.LoadTexture("Player Border", PLAYER_BORDER_FILEPATH);
		_border.setTexture(this->_data->assets.GetTexture("Player Border"));
		
	}
	void player::HandleInput()
	{
		sf::Event event;
		
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