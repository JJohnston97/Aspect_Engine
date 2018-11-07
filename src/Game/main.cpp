#include <Windows.h>	// Initalise for System pause and sleep
#include <GL\glew.h>	// Initalise OpenGL 
#include <glm/glm.hpp>	// Initalise GLM for Vecs
#include <SDL.h>		// Initalise SDL
#include "SDL.h"


#include <aspect/MeshRender.h> // Allows for the use of MeshRender.h from my engine
#include <aspect/Program.h>	// Allows for the use of Program.h from my engine
#include <aspect/Entity.h>	// Allows for the use of Entity.h from my engine
#include <aspect/Audio.h>   // Allows for the use of Audio.h from my engine
#include <aspect/Transform.h>
#include <aspect/BoxCollider.h>

#include <string>	// Initalise for the use of string
#include <iostream>	// Inialise use for debug and writing to the console
#include <memory>	// Initalise memeory for use of smart and weak pointers


 // https://gamedev.stackexchange.com/questions/70648/build-unity-like-transform-class
void safe_Main()
{

	std::shared_ptr<Aspect::Engine::Program> p = Aspect::Engine::Program::InitSDL(); // Create a smart pointer call p that is equal to the program
	
	std::shared_ptr<Aspect::Engine::Entity> e = p->addEntity();							 // initalise function
	
	e->addComponent<Aspect::Engine::MeshRender>();
	e->addComponent<Aspect::Engine::BoxCollider>();

	e->getComponent <Aspect::Engine::Transform>()->Rotate(0, -10, 0);
	//e->getComponent<Aspect::Engine::Transform>()->setScale(1.5f, 3.0f, 3.0f);

	std::shared_ptr<Aspect::Engine::Audio> ac = std::make_shared<Aspect::Engine::Audio>("../Contrib/choose.ogg");
	ac->play();

	



	p->Start(); // The start of the game
	

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