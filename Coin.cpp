//#include "stdafx.h"
#include "Coin.h"
#include "Player.h"
#include "Enemy.h"
#include "Track.h"

Coin::Coin()
{
	collides = false;
	bodyTextSprite.Add("$$");
	bodyTextSprite.SetPosition((rand() % 31) + 3, 0);

	body.SetLeft(bodyTextSprite.GetPosition().X);
	body.SetTop(0);
	body.SetWidth(bodyTextSprite.GetWidth()); //2 bo 2 znaki
	body.SetHeight(bodyTextSprite.GetHeight()); //1 bo 1 wiersz
}

Coin::~Coin()
{
}

void Coin::Move()
{
	int XCoord = body.GetLeft();
	int YCoord = body.GetTop() + 1;

	body.SetTop(YCoord);
	bodyTextSprite.SetPosition(XCoord, YCoord);
}

void Coin::IsColliding(Track _track)
{
	if (body.CheckIfCollides(_track.GetLeftBorder()) || body.CheckIfCollides(_track.GetLeftBorder())) //Jeœli jedno LUB drugie zwróci true
	{
		collides = true;	//Jeœli koliduje z lew¹ lub praw¹ œcian¹ toru to ustaw flagê collides na true.
	}						//Flaga ta bêdzie sprawdzana do ustalenia czy usun¹æ obiekt czy nie
	if (body.GetTop() >= _track.GetLeftBorder().GetBottom())
	{
		collides = true;
	}
}

void Coin::IsColliding(Player _player)
{
	if (body.CheckIfCollides(_player.GetBody()))
	{
		collides = true;
	}
}

void Coin::IsColliding(Enemy _enemy)
{
	if (body.CheckIfCollides(_enemy.GetBody()))
	{
		collides = true;
	}
}

void Coin::IsColliding(Coin _coin)
{
	//Przepuœæ - nic nie rób
}

void Coin::Draw(TextWindow _textWindow)
{
	_textWindow.Draw(bodyTextSprite);
}

void Coin::SetPosition(int XCoord, int YCoord)
{
	body.SetLeft(XCoord);
	body.SetTop(YCoord);
}

Box & Coin::GetBody()
{
	return body;
}

bool Coin::IsExisting()
{
	return !collides;
}

Movable::type Coin::GetType()
{
	return COIN;
}
