#pragma once
#include "Point.h"

class InputListener
{
public:
	InputListener()
	{
	}
	~InputListener()
	{
	}

	virtual void onKeyDown(int key) = 0;
	virtual void onKeyUp(int key) = 0;

	virtual void onMouseMove(const Point& mouse_pos) = 0;

	virtual void onLeftMouseDown(const Point& mouse_pos) = 0;
	virtual void onRightMouseDown(const Point& mouse_pos) = 0;

	virtual void onLeftMouseUp(const Point& mouse_pos) = 0;
	virtual void onRightMouseUp(const Point& mouse_pos) = 0;
};