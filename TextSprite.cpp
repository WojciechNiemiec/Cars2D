#include "TextSprite.h"

TextSprite::TextSprite()
{
}

TextSprite::~TextSprite()
{
}

void TextSprite::Add(std::string line)
{
	sprite.push_back(line); 
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
	return sprite.back().size(); 
}

int TextSprite::GetHeight()
{
	return sprite.size(); 
}

