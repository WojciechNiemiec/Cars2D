#pragma once
#include <iostream>
#include <windows.h>
#include <list>

class TextSprite
{
private:
	std::list<std::string> sprite; 
	COORD position; 

public:
	TextSprite();
	~TextSprite();
	void Add(std::string line);
	void SetPosition(int XCord, int YCord);
	COORD GetPosition();
	std::list<std::string> & GetSprite(); 
	int GetWidth();
	int GetHeight();
};
