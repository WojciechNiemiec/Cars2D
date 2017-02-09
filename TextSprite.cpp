//#include "stdafx.h"
#include "TextSprite.h"

TextSprite::TextSprite()
{
}

TextSprite::~TextSprite()
{
}

void TextSprite::Add(std::string line)
{
	sprite.push_back(line); //dodajê linijkê tekstu do listy
}

void TextSprite::SetPosition(int XCord, int YCord)
{
	position.X = XCord;
	position.Y = YCord;
}

COORD TextSprite::GetPosition()
{
	return position;
}

std::list<std::string> & TextSprite::GetSprite()
{
	return sprite;
}

int TextSprite::GetWidth()
{
	return sprite.back().size(); //sprite.back() zwraca ostatni¹ linijkê (string) sprajta i dla tej linijki wywo³ujemy size
}

int TextSprite::GetHeight()
{
	return sprite.size(); //size zwraca d³ugoœæ listy sprite
}

