//#include "stdafx.h"
#include "TextWindow.h"

//Generalnie to co tu siê dzieje jest trudne i zostaw to sobie na koniec.
//Korzystam tutaj z Windows API. Da³o siê to zrobiæ proœciej efekt by³ by gorszy a po za tym chcia³em pobawiæ siê tymi funkcjami.
//windowsowe API (Application Programing Interface) jest napisane w jêzyku C czyli strukturalnie.
//Poni¿szy kod to implementacja klasy TextWindow (kod obiektowy) w oparciu o bibliotekê z jêzyka C (kod strukturalny).

TextWindow::TextWindow()
{
	switcher = false;
	windowBufferOne = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	windowBufferTwo = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	activeWindowBuffer = &windowBufferOne;
	backgroundWindowBuffer = &windowBufferTwo;
	//Tworzê dwa bufory dla ekranu konsoli. Wszystko co piszê wewn¹trz bufora jest niewidoczne na ekranie konsoli dopóki
	//nie ustawiê danego bufora jako aktywny. Chodzi o to ¿e operacja uaktywniania bufora jest du¿o szybsza ni¿ pisanie
	//bezpoœrednio na oknie konsoli. Gdybym pisa³ bezpoœrednio na oknie konsoli by³oby widaæ nieprzyjemne migotanie.
	//Jak nie wierzysz spróbuj w nieskoñczonej pêtli zape³niæ ekran 10000 liter a nastêpnie to czyœciæ i tak w kó³ko.
	//Mo¿na by³o zminimalizowaæ miganie w mniej zaawansowany i mniej efektywny sposób ale chcia³em siê przy okazji czegoœ nauczyæ.
	//Poczytaj sobie czym w ogóle jest podwójne buforowanie.
}

TextWindow::TextWindow(unsigned int Width, unsigned int Height)
{
	switcher = false;
	windowBufferOne = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	windowBufferTwo = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	activeWindowBuffer = &windowBufferOne;
	backgroundWindowBuffer = &windowBufferTwo;
	
	SMALL_RECT rect = { 0 ,0, Width, Height };

	SetConsoleWindowInfo(windowBufferOne, 1, &rect); //ta funkcja jest doœæ uparta i jak nie spodobaj¹ siê jej dane to je ignoruje
	SetConsoleWindowInfo(windowBufferTwo, 1, &rect); //mo¿na zrobiæ walidacjê danych i jak bêd¹ za du¿e to wstawiæ maksymalne mo¿liwe
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

	//for each (std::string line in sprite.GetSprite())
	for( std::list<std::string>::iterator line = sprite.GetSprite().begin();
        line != sprite.GetSprite().end();
        ++line)
	{
		//for each (char ch in line)
		for( std::string::iterator ch = (*line).begin();
        	ch != (*line).end();
        	++ch)
		{
			SetConsoleCursorPosition(*backgroundWindowBuffer, cord); //w oknie bêd¹cym w tle ustawiam kursor na odpowiednich wspó³rzêdnych
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

	switcher = !switcher; //zmiana stanu prze³¹cznika
	activeWindowBuffer = (switcher == false) ? &windowBufferOne : &windowBufferTwo; //skrócony if
	//Jeœli prze³¹cznik wy³¹czony to aktywne jest okno jeden, jak w³¹czony to aktywne jest okno dwa
	backgroundWindowBuffer = (switcher == false) ? &windowBufferTwo : &windowBufferOne;
	
	SetConsoleActiveScreenBuffer(*activeWindowBuffer);
}
