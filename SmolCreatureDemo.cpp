// SmolCreatureDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Events.h"

int main()
{
	// Call a series of Events
	Handler player = Events::Intro();
	Events::WakeUp(player.GetName());
	Events::TouchGrass(player.GetName());
}
