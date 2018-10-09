#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>

#include <SDL.h>
#include "SDL.h"


#include <aspect/Program.h>
#include <aspect/Screen.h>

#include <string>
#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{

	Aspect::Engine::InitSDL();	// Load Libarys no loop yes or no
	
	// Add comp, add ents add ent function to make object loads before game runs
	// run game with while loop
	
	std::cout << "Ran through" << std::endl;
	

	return 0;
}