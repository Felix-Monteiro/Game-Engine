#pragma once
#include <iostream>
#include <time.h>
#include <stdio.h>
#include "pch.h"
using namespace std;

class GameComponent
{
private:
	int id;
    int static instances;

public:
	GameComponent();
    virtual void Update(const tm*);
};

