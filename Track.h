#pragma once
#include <map>
#include "Movable.h"
#include "Box.h"
#include "TextSprite.h"
#include "TextWindow.h"

class Track
{
private:
	enum selector
	{
		one,
		two,
		three
	}spriteSelector;

	Box leftBorder;
	Box rightBorder;
	std::map<selector, TextSprite> trackTextSprite;

	void GenerateTextSprite();
public:
	Track();
	~Track();
	void Draw(TextWindow _textWindow);
	Box & GetLeftBorder();
	Box & GetRightBorder();
	bool IsExisting() { return true; };
};
