#pragma once
#include <iostream>
#include <windows.h>

#include "TextSprite.h"

class TextWindow //Implementujê tutaj konsolowe podwójne buforowanie. Poczytaj co to a implementacjê tej klasy ogarnij na koñcu
{
private:
	bool switcher; //okreœla który buffer jest aktywny a który nie
	HANDLE windowBufferOne; //pierwszy bufor okna - szczegó³y w konstruktorze
	HANDLE windowBufferTwo; //drugi
	HANDLE* activeWindowBuffer; //tym wybieram który bufor aktualnie jest aktywny czyli widoczny
	HANDLE* backgroundWindowBuffer; //tym wybieram który bufor s³u¿y do malowania w nim

public:
	TextWindow();
	TextWindow(unsigned int Width, unsigned int Height);
	~TextWindow();
	void Clear(); //metoda czyszcz¹ca bufer
	void Draw(TextSprite sprite); //metoda rysuj¹ca w tym oknie buforowym
	void Display(); //wyœwietla obraz - zawartoœæ bufferWindow idzie do consoleWindow
};
