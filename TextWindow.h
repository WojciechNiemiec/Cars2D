#pragma once
#include <iostream>
#include <windows.h>

#include "TextSprite.h"

class TextWindow 
{
private:
	bool switcher; 
	HANDLE windowBufferOne; 
	HANDLE windowBufferTwo; 
	HANDLE* activeWindowBuffer; 
	HANDLE* backgroundWindowBuffer; 

public:
	TextWindow();
	TextWindow(unsigned int Width, unsigned int Height);
	~TextWindow();
	void Clear();
	void Draw(TextSprite sprite); 
	void Display(); 
};
