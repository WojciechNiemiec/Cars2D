#pragma once

class Track;
class Player;
class Enemy;
class Coin;
class Box;
class TextWindow;

class Movable
{
public:
	Movable();
	~Movable();
	virtual void Move() = 0; 
	virtual void IsColliding(Track _track) = 0;
	virtual void IsColliding(Player _player) = 0;
	virtual void IsColliding(Enemy _enemy) = 0;
	virtual void IsColliding(Coin _coin) = 0;
	virtual void SetPosition(int XCoord, int YCoord) = 0;
	virtual Box & GetBody() = 0;
	virtual bool IsExisting() = 0;
	virtual void Draw(TextWindow _textWindow) = 0;

	enum type
	{
		COIN,
		ENEMY,
		PLAYER,
		TRACK,
	};

	virtual type GetType() = 0;
};
