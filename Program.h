#pragma once
#include <list>

#include "Movable.h"
#include "Track.h"

class TextWindow;

class Program
{
private:
	std::list<Movable*> movable;
	Track track;
	Player* player;
	int callsToCreate;
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
	void GetDataFromPlayer(); 
	void Delay();
	bool GetIsPlayerAlive();
	void Run();
};
