#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>

#include <glm/glm.hpp>

#include <SDL.h>
#include "SDL.h"


#include <aspect/Program.h>
#include <aspect/Entity.h>

#include <string>
#include <iostream>
#include <memory>

int main(int argc, char *argv[])
{

	std::shared_ptr<Aspect::Engine::Program> p = Aspect::Engine::Program::InitSDL();	// Load Libarys no loop yes or no
	p->Start();
																						
																						//Aspect::Engine::Program::Start();
	//Aspect::Engine::Entity::addEntity();
	
	// Add comp, add ents add ent function to make object loads before game runs
	// run game with while loop
	
	std::cout << "Ran through" << std::endl;


	return 0;
}