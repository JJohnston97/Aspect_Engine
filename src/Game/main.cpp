/// @Main
/// @The main game file where the objects are create at the start and the game is run

// System Includes
#include <Windows.h>	// Initalise for System pause and sleep
#include <GL\glew.h>	// Initalise OpenGL 
#include <glm/glm.hpp>	// Initalise GLM for Vecs
#include <SDL.h>		// Initalise SDL
#include "SDL.h"		// Initalise SDL.h
#include <string>	// Initalise for the use of string
#include <iostream>	// Inialise use for debug and writing to the console
#include <memory>	// Initalise memeory for use of smart and weak pointers


// Engine Includes
#include <aspect/MeshRender.h> // Allows for the use of MeshRender.h from my engine
#include <aspect/Program.h>	 // Allows for the use of Program.h from my engine
#include <aspect/Entity.h>	// Allows for the use of Entity.h from my engine
#include <aspect/Audio.h>   // Allows for the use of Audio.h from my engine
#include <aspect/Transform.h> // Allows for the use of Transform.h from my engine
#include <aspect/BoxCollider.h> // Allows for the use of BoxCollider.h from my engine
#include <aspect/Camera.h> // Allows for the use of Camera.h from my engine



void safe_Main()
{

	std::shared_ptr<Aspect::Engine::Program> p = Aspect::Engine::Program::InitSDL(); // Create a smart pointer call p that is equal to the program
	
	
	std::shared_ptr<Aspect::Engine::Entity> c = p->addEntity();			// Add entity C to the program entities list
	std::shared_ptr<Aspect::Engine::Entity> player = p->addEntity();	// Add entity Player to the program entities list


	std::shared_ptr<Aspect::Engine::MeshRender> mr = player->addComponent<Aspect::Engine::MeshRender>();	// Create a mesh renderer and add it to the player

	mr->Triangle();								// Create a triangle object under mesh renderer for the player
	mr->setTexture("../Images/send_help.png");  // Set the texture of that object

	player->getComponent<Aspect::Engine::Transform>()->Translate(-7.6802f, -7.7f, 0.0f); // Set the players first position to be
	

	player->addComponent<Aspect::Engine::BoxCollider>(); // Add a box collider
	c->addComponent<Aspect::Engine::Camera>();			// Add second cam


	c->getComponent<Aspect::Engine::Transform>()->Translate(0.0f, 0.0f, 22.0f); //THIS IS THE CAMERA
	

	p->Start(c, player); // The start of the game
	

}

int main(int argc, char *argv[])
{
	
	try // Try and start the engine but if anything goes wrong
	{
		safe_Main();

	}
	catch(std::exception& e) // Catch the exception and output it and end the program
	{
		std::cout << "Exception: " << e.what() << std::endl;

	}

	return 0;	// End program
}
 


// https://gamedev.stackexchange.com/questions/70648/build-unity-like-transform-class