#pragma once
#include <list>

#include "Movable.h"

class TextWindow;

class Program
{
private:
	std::list<Movable*> movable;
	Track track;
	Player* player;	//Obiekt klasy player stnieje zarówno w liœcie jak i tutaj. To ten sam obiekt. Mo¿e istnieæ w dwóch miejscach
					//jednoczeœnie dziêki zastosowaniu wskaŸników. Dok³adniej to jest w jednym miejscu a w wielu sa jego referencje
	int callsToCreate; //Liczba wywo³añ metody GenerateObjects do stworzenia wroga
	bool isPlayerAlive;
	int points;

public:
	Program();
	~Program();
	void GenerateObjects();
	void RemoveObjects();
	void CheckCollisions();
	void MoveObjects();
	void DrawObjects(TextWindow _textWindow);
	void DrawGameOver(TextWindow _textWindow);
	void GetDataFromPlayer(); //tu u¿ywam wskaŸnika na playera ¿eby nie iterowaæ po ca³ej liœcie i go nie szukaæ
	void Delay();
	bool GetIsPlayerAlive();
	
	//static int _Main();
};
