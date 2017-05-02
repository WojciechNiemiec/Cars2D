#include "TextWindow.h"

//ASCII double buffering
TextWindow::TextWindow()
{
	switcher = false;
	windowBufferOne = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	windowBufferTwo = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	activeWindowBuffer = &windowBufferOne;
	backgroundWindowBuffer = &windowBufferTwo;
}

TextWindow::TextWindow(unsigned int Width, unsigned int Height)
{
	switcher = false;
	windowBufferOne = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	windowBufferTwo = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	activeWindowBuffer = &windowBufferOne;
	backgroundWindowBuffer = &windowBufferTwo;
	
	SMALL_RECT rect = { 0 ,0, Width, Height };

	SetConsoleWindowInfo(windowBufferOne, 1, &rect);
	SetConsoleWindowInfo(windowBufferTwo, 1, &rect); 
}

TextWindow::~TextWindow()
{
}

void TextWindow::Clear()
{
	COORD topLeft = { 0 , 0 };
	CONSOLE_SCREEN_BUFFER_INFO bufferWindowInfo;
	DWORD written;

	GetConsoleScreenBufferInfo(*backgroundWindowBuffer, &bufferWindowInfo); //To ca³e info wykokrzystujê ¿eby wiedzieæ iloma spacjami wyczyœciæ ekran
	FillConsoleOutputCharacterA(*backgroundWindowBuffer, ' ', bufferWindowInfo.dwSize.X * bufferWindowInfo.dwSize.Y, topLeft, &written);
	SetConsoleCursorPosition(*backgroundWindowBuffer, topLeft);
}

void TextWindow::Draw(TextSprite sprite)
{
	COORD cord;
	DWORD written;
	cord = sprite.GetPosition();

	for( std::list<std::string>::iterator line = sprite.GetSprite().begin();
        line != sprite.GetSprite().end();
        ++line)
	{
		for( std::string::iterator ch = (*line).begin();
        	ch != (*line).end();
        	++ch)
		{
			SetConsoleCursorPosition(*backgroundWindowBuffer, cord);
			FillConsoleOutputCharacterA(*backgroundWindowBuffer, *ch, 1, cord, &written);
			cord.X++;
		}
		cord.X = sprite.GetPosition().X;
		cord.Y++;
	}
}

void TextWindow::Display()
{
	CONSOLE_SCREEN_BUFFER_INFO windowInfo;
	GetConsoleScreenBufferInfo(&activeWindowBuffer, &windowInfo);
	SetConsoleScreenBufferSize(&backgroundWindowBuffer, windowInfo.dwSize);

	switcher = !switcher; 
	activeWindowBuffer = (switcher == false) ? &windowBufferOne : &windowBufferTwo;
	backgroundWindowBuffer = (switcher == false) ? &windowBufferTwo : &windowBufferOne;
	
	SetConsoleActiveScreenBuffer(*activeWindowBuffer);
}
