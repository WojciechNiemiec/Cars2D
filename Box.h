#pragma once

class Box
{
private:
	int left;
	int top;
	int width;
	int height;

public:
	Box();
	Box(int left, int top, int width, int height);
	~Box();
	bool CheckIfCollides(Box box);
	int GetLeft();
	int GetTop();
	int GetRight();
	int GetBottom();

	void SetLeft(int value);
	void SetTop(int value);
	void SetWidth(int value);
	void SetHeight(int value);
};
