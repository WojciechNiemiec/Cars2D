#pragma once

class Track;
class Player;
class Enemy;
class Coin;
class Box;
class TextWindow;

//To tylko deklaracje klas (brak cia³a). Jak widzisz nie ma tu ¿adnego nag³ówka który mówi³by o ich istnieniu.
//Klasa ta nabiorze sensu dopiero w klasach, które dziedzicz¹ po Movable. Te klasy zawieraj¹
//w plikach nag³ówkowych includy do prawdziwych TextSprite i TextWindow gdzie s¹ one ju¿ zdefiniowane

//Lubiê u¿ywaæ dziedziczenia w taki sposób jak interfejsów w innych jêzykach czyli bez ¿adnych pól i bez
//cia³ metod (metody czysto wirtualne). W ten sposób tylko okreœlam co dana klasa dziedzicz¹ca musi potrafiæ no i
//mogê traktowaæ je w zbiorczy sposób. Mogê zrobiæ tabelê typu Movable a w œrodku bêdzie jakiœ Coin, Player itp.
//Logiki nie dziedziczê tylko pakujê do takich jakby komponentów. Przyk³adem takiego komponentu jest klasa Box

class Movable
{
public:
	Movable();
	~Movable();
	virtual void Move() = 0; // = 0 oznacza metodê czysto wirtualn¹
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
