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
#include <aspect/Camera.h>

#include <string>	// Initalise for the use of string
#include <iostream>	// Inialise use for debug and writing to the console
#include <memory>	// Initalise memeory for use of smart and weak pointers


void safe_Main()
{

	std::shared_ptr<Aspect::Engine::Program> p = Aspect::Engine::Program::InitSDL(); // Create a smart pointer call p that is equal to the program
	
	std::shared_ptr<Aspect::Engine::Entity> e = p->addEntity();
	std::shared_ptr <Aspect::Engine::Entity> o = p->addEntity();
	std::shared_ptr<Aspect::Engine::Entity> c = p->addEntity();
	std::shared_ptr<Aspect::Engine::Entity> player = p->addEntity();


	std::shared_ptr<Aspect::Engine::MeshRender> mr = e->addComponent<Aspect::Engine::MeshRender>();
	std::shared_ptr<Aspect::Engine::MeshRender> mr2 = player->addComponent<Aspect::Engine::MeshRender>();
	std::shared_ptr<Aspect::Engine::MeshRender> mr3 = o->addComponent<Aspect::Engine::MeshRender>();
	
	player->getComponent<Aspect::Engine::Transform>()->Translate(-8.6802f, -7.0f, 0.0f);
	o->getComponent<Aspect::Engine::Transform>()->Translate(-4, 0, 0);

	
	e->addComponent<Aspect::Engine::BoxCollider>();
	player->addComponent<Aspect::Engine::BoxCollider>();
	o->addComponent<Aspect::Engine::BoxCollider>();
	c->addComponent<Aspect::Engine::Camera>();			// Add second cam
	

	/*for (size_t i = 0; i < 5; i++)
	{
		for (size_t x = 0; x < 3; x=+2)
		{
			std::shared_ptr<Aspect::Engine::Entity> en = p->addEntity();
			std::shared_ptr<Aspect::Engine::MeshRender> gmr = en->addComponent<Aspect::Engine::MeshRender>();
			en->getComponent<Aspect::Engine::Transform>()->Translate(x, 0.0, 0.0);
			en->addComponent<Aspect::Engine::BoxCollider>();
		}
	}*/


	c->getComponent<Aspect::Engine::Transform>()->Translate(0.0f, 0.0f, 20.0f); //THIS IS THE CAMERA
	

	p->Start(c, player); // The start of the game
	

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