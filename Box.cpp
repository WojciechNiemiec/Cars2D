#include "Box.h"

Box::Box()
{
}

Box::Box(int left, int top, int width, int height)
{
	this->left = left;
	this->top = top;
	this->width = width;
	this->height = height;
}

Box::~Box()
{
}

bool Box::CheckIfCollides(Box box)
{
	bool collidesVertically = false;
	bool collidesHorizontally = false;

	if (((left >= box.GetLeft()) && (left <= box.GetRight())) ||
		((GetRight() >= box.GetLeft()) && (GetRight() <= box.GetRight())) ||
		((box.GetLeft() >= left) && (box.GetLeft() <= GetRight())) ||
		((box.GetRight() >= GetLeft()) && (box.GetRight() <= GetRight())))
	{
		collidesVertically = true;
	}

	if (((top >= box.GetTop()) && (top <= box.GetBottom())) ||
		((GetBottom() >= box.GetTop()) && (GetBottom() <= box.GetBottom())) ||
		((box.GetTop() >= top) && (box.GetTop() <= GetBottom())) ||
		((box.GetBottom() >= GetTop()) && (box.GetBottom() <= GetBottom())))
	{
		collidesHorizontally = true;
	}

	return collidesVertically && collidesHorizontally;
}

int Box::GetLeft()
{
	return left;
}

int Box::GetTop()
{
	return top;
}

int Box::GetRight()
{
	return left + width;
}

int Box::GetBottom()
{
	return top + height;
}

void Box::SetLeft(int value)
{
	left = value;
}

void Box::SetTop(int value)
{
	top = value;
}

void Box::SetWidth(int value)
{
	width = value;
}

void Box::SetHeight(int value)
{
	height = value;
}

