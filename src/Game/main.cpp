#include <Windows.h>	// Initalise for System pause and sleep
#include <GL\glew.h>	// Initalise OpenGL 
#include <glm/glm.hpp>	// Initalise GLM for Vecs
#include <SDL.h>		// Initalise SDL
#include "SDL.h"

#include <aspect/Program.h>	// Allows for the use of Program.h from my engine
#include <aspect/Entity.h>	// Allows for the use of Entity.h from my engine

#include <string>	// Initalise for the use of string
#include <iostream>	// Inialise use for debug and writing to the console
#include <memory>	// Initalise memeory for use of smart and weak pointers

int main(int argc, char *argv[])
{

	std::shared_ptr<Aspect::Engine::Program> p = Aspect::Engine::Program::InitSDL(); // Create a smart pointer call p that is equal to the program
																					 // initalise function
	p->Start(); // Starts program loop

	return 0;	// End program
}