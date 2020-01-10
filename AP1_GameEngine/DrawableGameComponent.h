#pragma once
#include "GameComponent.h"
#include <time.h>
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include "pch.h"
using namespace std;

class DrawableGameComponent : public GameComponent
{
public:
	const int SCREEN_HEIGHT=20;
	const int SCREEN_WIDTH=80;
	enum Direction { Left, Right, Up, Down };
	Direction direction;
	DrawableGameComponent(int x, int y);
	void Update(const tm* eventTime);

private:
	void ChangeDirection();
	void Draw();
	int x;
	int y;
	
};


