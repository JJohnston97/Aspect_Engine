#include <Windows.h>	// Initalise for System pause and sleep
#include <GL\glew.h>	// Initalise OpenGL 
#include <glm/glm.hpp>	// Initalise GLM for Vecs
#include <SDL.h>		// Initalise SDL
#include "SDL.h"


#include <aspect/MeshRender.h> // Allows for the use of MeshRender.h from my engine
#include <aspect/Program.h>	// Allows for the use of Program.h from my engine
#include <aspect/Entity.h>	// Allows for the use of Entity.h from my engine
#include <aspect/Audio.h>   // Allows for the use of Audio.h from my engine

#include <string>	// Initalise for the use of string
#include <iostream>	// Inialise use for debug and writing to the console
#include <memory>	// Initalise memeory for use of smart and weak pointers

void safe_Main()
{

	std::shared_ptr<Aspect::Engine::Program> p = Aspect::Engine::Program::InitSDL(); // Create a smart pointer call p that is equal to the program
	
	std::shared_ptr<Aspect::Engine::Entity> e = p->addEntity();							 // initalise function
	e->addComponent<Aspect::Engine::MeshRender>();

	std::shared_ptr<Aspect::Engine::Audio> ac = std::make_shared<Aspect::Engine::Audio>("../Contrib/choose.ogg");
	ac->play(1.0f, 0.5f, 0.5f);
	
	p->Start(); // Starts program loop
	

}

int main(int argc, char *argv[])
{
	safe_Main();
	/*try
	{
		safe_Main();

	}
	catch(std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;

	}*/

	return 0;	// End program
}