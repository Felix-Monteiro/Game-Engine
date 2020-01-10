#include "Game.h"
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <time.h>
#include <ctime>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

Game::Game(int maxComponents):componentCount(maxComponents)
{
	componentCount = 0;//Number components in array.
	//array of pointers of type GameComponent(components).
	components = new GameComponent * [maxComponents];
}

void Game::Add(GameComponent*c) 
{
	//adds a new (GameComponent/DrawableGameComponent) object to an array of pointers of type GameComponent (components).
	 components[componentCount]=c;
	 componentCount++;
	

}

void Game::Run()
{

	//Invocation of the function whose address has been assigned (using SetInitialise) to the Initialise pointer. 
	initialise();

	time_t realtime = time(0);
	const tm* timeinfo = localtime(&realtime);
	int variable = timeinfo->tm_sec;

	while (timeinfo->tm_sec < variable+5)//should be invoked once every second, but should only execute 5 times.
	{
		//Iterates through the components array invoking the component’s Update member functions.
		for (int n = 0; n < componentCount; n++)
		{
			components[n]->Update(timeinfo);
		}
		Sleep(TICKS_1000MS);
		time_t realtime = time(0);
		timeinfo = localtime(&realtime);
	}	

	//Invocation of the function whose address has been assigned (using SetTerminate) to the terminate pointer. 
	terminate();
}
void Game::SetInitialise(FP init) 
{
	//Assigns the address of a standalone function to the Initialise data member.
	initialise = init;

}

void Game::SetTerminate(FP term) 
{
	//Assigns the address of a standalone function to the terminate data member.
	terminate = term;

}

