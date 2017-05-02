#include <iostream>
#include <ctime>
#include <conio.h> //_kbhit()
#include <algorithm>

#include "TextSprite.h"
#include "TextWindow.h"
#include "Coin.h"
#include "Enemy.h"
#include "Player.h"
#include "Track.h"
#include "Program.h"

Program::Program()
{
	isPlayerAlive = true;
	Player* p = new Player();
	player = p;
	callsToCreate = 17;
	
	movable.push_back(p);
}

Program::~Program()
{
}

void Program::GenerateObjects()
{
	static int i = 0;
	i++;
	
	if (i == callsToCreate)
	{
		i = 0;
		Enemy* e = new Enemy();
		movable.push_back(e);

		if (points < 500)
		{
			callsToCreate = 17;
		}
		else if (points < 1000)
		{
			callsToCreate = 15;
		}
		else if (points < 1500)
		{
			callsToCreate = 13;
		}
		else if (points < 2000)
		{
			callsToCreate = 11;
		}
		else
		{
			callsToCreate = 9;
		}
	}
	if (i % 8 == 0)
	{
		Coin* c = new Coin();

		movable.push_back(c);
	}
}

void Program::RemoveObjects()
{
	//for each (Movable* var in movable)
	for( std::list<Movable*>::iterator var = movable.begin();
         var != movable.end();
         ++var)
	{
		if ((*var)->IsExisting() == false)
		{
			delete (*var);
			movable.remove(*var);

			break;
		}
	}
}

void Program::CheckCollisions()
{
	int i = 0;
	int j = 0;

	for( std::list<Movable*>::iterator var = movable.begin();
         var != movable.end();
         ++var)
	{
		i++;
		(*var)->IsColliding(track);

		for( std::list<Movable*>::iterator collider = movable.begin();
        	collider != movable.end();
        	++collider)
		{
			j++;
			
			if (i != j) 
			{
				switch ((*collider)->GetType())
				{
				case Movable::COIN:
					(*var)->IsColliding(*(Coin*)(*collider)); 
					break;	
				case Movable::ENEMY:				
					(*var)->IsColliding(*(Enemy*)(*collider));
					break;							
				case Movable::PLAYER:	
					(*var)->IsColliding(*(Player*)(*collider)); 
					break;
				default:
					break;
				}
			}
		}

		j = 0;
	}
}

void Program::MoveObjects()
{
	for( std::list<Movable*>::iterator var = movable.begin();
        var != movable.end();
        ++var)
	{
		(*var)->Move();
	}
}

void Program::DrawObjects(TextWindow _textWindow)
{
	track.Draw(_textWindow);

	for( std::list<Movable*>::iterator var = movable.begin();
        var != movable.end();
        ++var)
	{
		(*var)->Draw(_textWindow);
	}
}

void Program::DrawGameOver(TextWindow _textWindow)
{
	std::string tekst;
	TextSprite GameOverSprite;

	tekst = "***GAME OVER***";
	GameOverSprite.Add(tekst);
	tekst = "";
	GameOverSprite.Add(tekst);
	tekst = "Your score is: " + IntToStr(points);
	GameOverSprite.Add(tekst);
	GameOverSprite.SetPosition(20, 20);

	_textWindow.Draw(GameOverSprite);
}

void Program::GetDataFromPlayer()
{
	 isPlayerAlive = player->IsExisting();
	 points = player->GetPoints();
}

void Program::Delay()
{
	if (isPlayerAlive)
	{
		Sleep(30);
	}
	else
	{
		Sleep(3000);
	}
}

bool Program::GetIsPlayerAlive()
{
	return isPlayerAlive;
}

void Program::Run()
{
	srand(time(NULL));
	TextWindow textWindow(65, 50);
	Program program; 

	while (program.GetIsPlayerAlive())
	{	
		program.GenerateObjects(); 
		program.CheckCollisions(); 
		program.MoveObjects(); 
		program.GetDataFromPlayer(); 
		program.RemoveObjects(); 
		program.DrawObjects(textWindow);

		textWindow.Display();
		program.Delay();
		textWindow.Clear();
	}
	
	program.DrawGameOver(textWindow);
	textWindow.Display();
	program.Delay();
}
