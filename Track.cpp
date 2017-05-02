#include "Track.h"

void Track::GenerateTextSprite()
{
	TextSprite sprite1, sprite2, sprite3;

	for (int i = 0; i < 15; i++)
	{
		sprite1.Add("||-                |                -||");
		sprite1.Add("||-                                 -||");
		sprite1.Add("||-                                 -||");
	}
	for (int i = 0; i < 15; i++)
	{
		sprite2.Add("||-                                 -||");
		sprite2.Add("||-                |                -||");
		sprite2.Add("||-                                 -||");
	}
	for (int i = 0; i < 15; i++)
	{
		sprite3.Add("||-                                 -||");
		sprite3.Add("||-                                 -||");
		sprite3.Add("||-                |                -||");
	}

	sprite1.SetPosition(0, 0);
	sprite2.SetPosition(0, 0);
	sprite3.SetPosition(0, 0);
	
	trackTextSprite.insert(std::pair<selector, TextSprite>(one, sprite1));
	trackTextSprite.insert(std::pair<selector, TextSprite>(two, sprite2));
	trackTextSprite.insert(std::pair<selector, TextSprite>(three, sprite3));
}

Track::Track()
{
	const int BorderWidth = 3;
	spriteSelector = one;

	GenerateTextSprite();

	trackTextSprite[one].SetPosition(0, 0);

	leftBorder.SetLeft(0);
	leftBorder.SetWidth(BorderWidth);
	leftBorder.SetTop(0);
	leftBorder.SetHeight(trackTextSprite[one].GetHeight());

	rightBorder.SetLeft(trackTextSprite[one].GetWidth() - BorderWidth);
	rightBorder.SetWidth(BorderWidth);
	rightBorder.SetTop(0);
	rightBorder.SetHeight(trackTextSprite[one].GetHeight());
}

Track::~Track()
{
}

void Track::Draw(TextWindow _textWindow)
{
	switch (spriteSelector)
	{
	case one:
		_textWindow.Draw(trackTextSprite[one]);
		spriteSelector = two;
		break;
	case two:
		_textWindow.Draw(trackTextSprite[two]);
		spriteSelector = three;
		break;
	case three:
		_textWindow.Draw(trackTextSprite[three]);
		spriteSelector = one;
		break;
	default:
		break;
	}
}

Box & Track::GetLeftBorder()
{
	return leftBorder;
}

Box & Track::GetRightBorder()
{
	return rightBorder;
}

