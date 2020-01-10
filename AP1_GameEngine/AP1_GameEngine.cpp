//Implementation of the classes
#include "DrawableGameComponent.h"
#include "Game.h"
#include "GameComponent.h"
#include <iostream>
#include <functional>
#include <string>
#include "pch.h"
using namespace std;

//The two standalone functions 

void initialise() {
	cout << "Initialising Game" << endl;

}

void terminate() {
	cout << "Terminating Game" << endl;
}

int main()
{
	//A dynamic instance of Game.
	Game g1(2);

	//GameComponent Object.
	GameComponent obj1;

	//DrawableGameComponentObject.
	DrawableGameComponent obj2(0,0);

	//Invocation of SetInitialise passing it one of the standalone function addresses.
	g1.SetInitialise(initialise);	

	//Invocation of SetTerminate passing it the other standalone function address.
	g1.SetTerminate(terminate);

	//The addition of a GameComponent object with an id of 1 to the Game object.
	g1.Add(&obj1);

	//The addition of a DrawableGameComponent object with an id of 2 and a position of x = 0, y = 0 to the game object.
	g1.Add(&obj2);

	//Invocation of the game object’s Run member function.
	g1.Run();
}

