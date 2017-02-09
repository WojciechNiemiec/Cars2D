//#include "stdafx.h"
#include <cstdlib>

#include "Enemy.h"
#include "Player.h"
#include "Coin.h"
#include "Track.h"

Enemy::Enemy()
{
	alive = true;

	int variable = rand() % 8;
	direction = None;

	switch (variable)
	{
	case 1:
	case 2:
		direction = Left;
		break;
	case 3:
	case 4:
		direction = Right;
		break;
	default:
		direction = None;
		break;
	}

	bodyTextSprite.Add(" ____ "); // mo¿esz sobie bez przeszkód zmieniæ ten obrazek a box dopasuje swoje wymiary i kolizje bêd¹ dzia³aæ
	bodyTextSprite.Add("O __ O");
	bodyTextSprite.Add("|[__]|");
	bodyTextSprite.Add("|\\__/|"); // tu s¹ dwa backslashe \\ bo pojedynczy s³uzy do robienia znaków specjalnych np '\0' - koniec textu, '\n' - enter, '\t' - tabulator
	bodyTextSprite.Add("O,~~,O");

	bodyTextSprite.SetPosition(rand() % 34, 0);

	body.SetLeft(bodyTextSprite.GetPosition().X);
	body.SetTop(bodyTextSprite.GetPosition().Y);
	body.SetHeight(bodyTextSprite.GetHeight());
	body.SetWidth(bodyTextSprite.GetWidth());
}

Enemy::~Enemy()
{
}

void Enemy::Move()
{
	int XCoord = body.GetLeft();
	int YCoord = body.GetTop();

	switch (direction)
	{
	case Left:
		XCoord--;
		YCoord++;
		break;
	case Right:
		XCoord++;
		YCoord++;
		break;
	default:
		YCoord += 2;
		break;
	}

	body.SetLeft(XCoord);
	body.SetTop(YCoord);
	bodyTextSprite.SetPosition(XCoord, YCoord);
}

void Enemy::IsColliding(Track _track)
{
	if (body.CheckIfCollides(_track.GetLeftBorder()))
	{
		direction = Right;
	}
	if (body.CheckIfCollides(_track.GetRightBorder()))
	{
		direction = Left;
	}
	if (body.GetTop() >= _track.GetLeftBorder().GetBottom())
	{
		alive = false; // Jak bêdzie poni¿ej toru to niech umiera. Btw wspó³rzêdna Y na konsoli zawsze roœnie w dó³ st¹d operator >= a nie <=
	}
}

void Enemy::IsColliding(Player _player)
{
	if (body.CheckIfCollides(_player.GetBody()))
	{
		alive = false;
	}
}

void Enemy::IsColliding(Enemy _enemy)
{
	if (body.CheckIfCollides(_enemy.GetBody())) //Jak koliduje z innym autem to zmienia kierunek
	{
		switch (direction)
		{
		case Left:
			direction = Right;
			break;
		case Right:
			direction = Left;
			break;
		default:
			break;
		}
	}
}

void Enemy::IsColliding(Coin _coin)
{
	//mo¿na zrobiæ ¿eby wróg przyspieszy³ jak dotknie coina ale po chuj xd
}

void Enemy::Draw(TextWindow _textWindow)
{
	_textWindow.Draw(bodyTextSprite);
}

void Enemy::SetPosition(int XCoord, int YCoord)
{
	body.SetLeft(XCoord);
	body.SetTop(YCoord);
}

Box & Enemy::GetBody()
{
	return body;
}

bool Enemy::IsExisting()
{
	return alive;
}

Movable::type Enemy::GetType()
{
	return ENEMY;
}

