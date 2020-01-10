#pragma once
#include "DrawableGameComponent.h"
#include <time.h>
#include <windows.h>
#include <stdio.h>
#include <ctime>
#include "pch.h"

using namespace std;

class Game
{
private:
	const int TICKS_1000MS=1000;
	typedef void (*FP)();
	FP initialise;
	FP terminate;
	int componentCount;
    GameComponent** components;

public:
	void Add(GameComponent*);
	Game(int maxComponents);
	void Run();
	void SetInitialise(FP init);
	void SetTerminate(FP term);

};



