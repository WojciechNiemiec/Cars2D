#pragma once
#include "Movable.h"
#include "Box.h"
#include "TextSprite.h"
#include "TextWindow.h"

class Coin : public Movable
{
	bool collides;
	Box body;
	TextSprite bodyTextSprite;

public:
	Coin();
	~Coin();
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
