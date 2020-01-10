#include "DrawableGameComponent.h"
#include <iostream>
#include "pch.h"

using namespace std;

DrawableGameComponent::DrawableGameComponent(int x, int y) 
{
	//Set the x and y values to zero and direction to Right.
	this->x=0;
	this->y=0;
	direction=Right;


}



void DrawableGameComponent::Update(const tm* eventTime)
{
	//Displays the object’s id and time of invocation.
	GameComponent::Update(eventTime);

	//Increments / decrements the x or y values depending upon the current direction(Up, Down, Left, Right) 
	switch (direction)
	{
	case(0):
	{
		if (x >= 0 && x <= SCREEN_WIDTH)
		{
			x++;
			direction = Left;

		}
		else if (x < 0) 
		{
			x = 0;
		}
		else if (SCREEN_WIDTH <= x)
		{
			x = SCREEN_WIDTH;
		}
			break;
	}
	case (1):
	{
		if (x >= 0 && x <= SCREEN_WIDTH)
		{
			x++;
			direction = Right;
		}
		else if (x <= 0)
		{
			x = 0;
		}
		else if (SCREEN_WIDTH <= x)
		{
			x = SCREEN_WIDTH;
		}
		break;
	}
	case (2):
	{
		if (y >= 0 && y <= SCREEN_HEIGHT)
		{
			y++;
			direction = Up;
		}
		else if (y <= 0) 
		{
			y = 0;
		}
		else if (SCREEN_HEIGHT <= y)
		{
			y = SCREEN_HEIGHT;
		}
		break;
	}
	case (3):
	{
		if (y >= 0 && y <= SCREEN_HEIGHT)
		{
			y--;
			direction = Down;
		}
		else if (y <= 0) 
		{
			y = 0;
		}
		else if (SCREEN_HEIGHT <= y)
		{
			y = SCREEN_HEIGHT;
		}
		break;
	}

    }

	//Invokes the Draw() member function
	Draw();

	//Invokes the ChangeDirection member function.
	ChangeDirection();

}


void DrawableGameComponent::ChangeDirection() 
{
	//assigns a new random direction to the direction data member.This direction is always different to the current direction.
	srand(time(NULL));
	switch (direction)
	{
	case(0):
	{
		do 
		{
			direction = Direction(rand() % 4);//it generates a random number in the range 0..3, that correspond to the numbers assigned to each direction.

		}while (direction == Left);
		break;
	}
	

	case (1):
	{
		do
		{
			direction = Direction(rand() % 4);


		} while (direction == Right);


		break;
	}
	case (2):
	{
		do
		{
			direction = Direction(rand() % 4);

		}while (direction == Up);
		break;
	}
	case (3):
	{
		do
		{
			direction = Direction(rand() % 4);

		}while (direction == Down);
		break;
	}
	}

}


void DrawableGameComponent::Draw() 
{
	//Displays the current direction along with the x and y values on the same line.

	if (direction==Right)
	{
		cout << "Right:" << " X:" << x << " Y:" << y << endl;
	}
	else if (direction==Left)
	{
		cout << "Left:" << " X:" << x << " Y:" << y << endl;
	}
	else if (direction == Up)
	{
		cout << "Up:" << " X:" << x << " Y:" << y << endl;
	}
	else if (direction == Down)
	{
		cout << "Down:" << " X:" << x << " Y:" << y << endl;
	}

}