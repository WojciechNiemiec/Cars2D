#pragma once
#include <iostream>
#include <windows.h>
#include <list>

class TextSprite
{
private:
	std::list<std::string> sprite; //lista to taka struktura danych która dopasowuje swoj¹ wielkoœæ do iloœci elementów. Obs³uguje siê podobnie ale dzia³a na ciut innej zasadzie
	COORD position; //COORD to struktura przyjmuj¹ca wspó³rzêdne x i y. Jest to czêœæ biblioteki windows.h i u¿ywa siê tego do rysowania na ekranie w okreœlonym punkcie

public:
	TextSprite();
	~TextSprite();
	void Add(std::string line);
	void SetPosition(int XCord, int YCord);
	COORD GetPosition();
	std::list<std::string> & GetSprite(); //zwracam referencjê (&) do listy
	int GetWidth();
	int GetHeight();
};
