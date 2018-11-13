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


void safe_Main()
{

	std::shared_ptr<Aspect::Engine::Program> p = Aspect::Engine::Program::InitSDL(); // Create a smart pointer call p that is equal to the program
	
	std::shared_ptr<Aspect::Engine::Entity> e = p->addEntity();
	std::shared_ptr<Aspect::Engine::Entity> n = p->addEntity();
	std::shared_ptr<Aspect::Engine::Entity> r = p->addEntity();

	std::shared_ptr<Aspect::Engine::MeshRender> mr = e->addComponent<Aspect::Engine::MeshRender>();
	std::shared_ptr<Aspect::Engine::MeshRender> mr2 = r->addComponent<Aspect::Engine::MeshRender>();
	
	mr->camera = n;
	mr2->camera = n;


	e->addComponent<Aspect::Engine::BoxCollider>();
	r->addComponent<Aspect::Engine::BoxCollider>();

	n->getComponent<Aspect::Engine::Transform>()->Translate(3.0f, 0.0f, 20.0f); //THIS IS THE CAMERA
	
	std::shared_ptr<Aspect::Engine::Audio> ac = std::make_shared<Aspect::Engine::Audio>("../Contrib/choose.ogg");
	
	ac->play();


	p->Start(n); // The start of the game
	

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
 


// https://gamedev.stackexchange.com/questions/70648/build-unity-like-transform-class