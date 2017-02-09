#pragma once
#include "Movable.h"
#include "Box.h"
#include "TextSprite.h"
#include "TextWindow.h"

class Enemy : public Movable
{
	enum Direction
	{
		None,
		Left,
		Right
	};
	
	bool alive;
	Direction direction;
	Box body;
	TextSprite bodyTextSprite;

public:
	Enemy();
	~Enemy();
	void Move();
	void IsColliding(Track _track);
	void IsColliding(Player _player);
	void IsColliding(Enemy _enemy);
	void IsColliding(Coin _coin);
	void Draw(TextWindow _textWindow);
	void SetPosition(int XCoord, int YCoord);
	Box & GetBody();
	bool IsExisting();
	type GetType();
};
