#include "GameComponent.h"
#include <time.h>
#include <iostream>
#include <stdio.h>
#include "pch.h"

using namespace std;

int GameComponent::instances; //Records a running total of the number of instances instantiated from either the GameComponent or DrawableGameComponent.

GameComponent::GameComponent() 
{
	id=0;
	instances++;
	id=instances;

}



void GameComponent::Update(const tm*timeinfo) 
{
	//Display the objects id and time at which the Update member function was invoked.
	cout << "ID: " << id << " Updated @: " << timeinfo->tm_hour << ":" << timeinfo->tm_min << ":" << timeinfo->tm_sec << endl;

}

