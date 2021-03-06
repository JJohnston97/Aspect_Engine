/// @Program.cpp
/// @Handles the main body of the program, game loop and creation of objects

// System Includes
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <GLM/gtc/type_ptr.hpp>
#include <GLM/gtc/matrix_transform.hpp>

// Project Includes
#include "Program.h"
#include "Entity.h"
#include "ShaderProgram.h"
#include "MeshRender.h"
#include "Transform.h"
#include "BoxCollider.h"
#include "Camera.h"
#include "Movement.h"
#include "Audio.h"

namespace Aspect
{
	namespace Engine
	{
		std::vector<std::shared_ptr<Entity> > Program::entities; // Entities list that all game objects are stored in

		SDL_Window *Program::_window;
		std::weak_ptr<Program> Program::self;

		bool Program::InitGlew()
		{
			//glewExperimental = GL_TRUE; // Enable Glew Experimental features

			GLenum err = glewInit();	// Initialise all glew
			if (GLEW_OK != err)			// If everything is not okay
			{
				std::cerr << "Error: GLEW failed to initialise with message: " << glewGetErrorString(err) << std::endl;	// Something has gone wrong with Glew, outputs error
				return false;
			}
			
			std::cout << "INFO: Using GLEW " << glewGetString(GLEW_VERSION) << std::endl;		// Lets you know what glew version you are using
			std::cout << "INFO: OpenGL Vendor: " << glGetString(GL_VENDOR) << std::endl;		// OpenGL vendor, nivida
			std::cout << "INFO: OpenGL Renderer: " << glGetString(GL_RENDERER) << std::endl;	// Graphics card for rendering
			std::cout << "INFO: OpenGL Version: " << glGetString(GL_VERSION) << std::endl;		// OpenGl Version
			std::cout << "INFO: OpenGL Shading Language Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl; // Shader langauge version

			return true;	// Returns true when initialised

		}

		std::shared_ptr<Program> Program::InitSDL()		// Initialise SDL function	
		{
			if (SDL_Init(SDL_INIT_VIDEO) < 0)	// If initialisation is not 0 (true) then something has gone wrong
			{
				std::cout << "Something has gone wrong, cannot initialise SDL!" << std::endl;	// Output an error message
				return false;																		// Exit the program
			}
			// We need to do this through SDL, so that it can set up the OpenGL drawing context that matches this
			//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);	// Using 4.3 OpenGL Major part 4
			//SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);	// Minor part 3
			//SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); // Using the latest version

			int windowPositionX = 100;	// Window position (Needs to change from this)
			int winowPositionY = 100;	// Window Y pos
			int windowWidth = 1080;
			int windowHeight = 900;

			_window = SDL_CreateWindow("Aspect Engine", windowPositionX, winowPositionY, windowWidth, windowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);	// Creates the SDL/OpenGL window
			//SDL_Renderer * renderer = SDL_CreateRenderer(_window, -1, 0);	// Creates the render, needs to between -1 and 0
			SDL_GLContext glcontext = SDL_GL_CreateContext(_window);			// Returns the OpenGl context associated with window

			if (!Program::InitGlew())	// If glew has not been initialised
			{
				return false;		// Close the program
			}


			glEnable(GL_DEPTH_TEST);	// Used to make sure what is in front are alwasy in front no matter the order they are drawn
		

			std::shared_ptr<Program> rtn = std::make_shared<Program>();
			self = rtn;

			rtn->device = alcOpenDevice(NULL);

			if (!rtn->device)
			{
				throw std::exception();
			}

			rtn->context = alcCreateContext(rtn->device, NULL);

			if (!rtn->context)
			{
				alcCloseDevice(rtn->device);
				throw std::exception();
			}

			if (!alcMakeContextCurrent(rtn->context))
			{
				alcDestroyContext(rtn->context);
				alcCloseDevice(rtn->device);
				throw std::exception();
			}


			return rtn;			// return rtn when set up
			
		}

		void Program::Start(std::shared_ptr<Entity> _cam, std::shared_ptr<Entity> _player)	// Start function controls game loop
		{
			running = true;

			bool cmdMoveForward = false, cmdMoveBackwards = false, cmdLeft = false, cmdRight = false; // Movement commands for player
			bool camMoveForward = false, camMoveBackwards = false, camLeft = false, camRight = false; // Movement commands for camera

			// Velocity and score values
			float velFast = -0.3f;
			float velSlow = 0.1;
			int scoreTime = 0;
			int score = 0;
			
			unsigned int lastTime = SDL_GetTicks();	// Used to work out time between frame
			
			std::shared_ptr<Aspect::Engine::Audio> ac = std::make_shared<Aspect::Engine::Audio>("../Contrib/Game_Music.ogg"); // Audio clip
			ac->play();

			while (running)
			{

				SDL_Event incomingEvent;
				while (SDL_PollEvent(&incomingEvent))	// Check if there is an event in the queue
				{
					switch (incomingEvent.type)			// If there is an event will return true and will fill the incoming event
					{									// Switch is based on the event type
					case SDL_QUIT:						// If the event type is quit
						End();					// End the program
						break;
					case SDL_KEYDOWN:
						switch (incomingEvent.key.keysym.sym)
						{
						case SDLK_d:
						{
							cmdLeft = true;
							break;
						}
						case SDLK_a:
						{
							cmdRight = true;
							break;
						}
						case SDLK_UP:
						{
							camMoveForward = true;
							break;
						}
						case SDLK_DOWN:
						{
							camMoveBackwards = true;
							break;
						}
						case SDLK_LEFT:
						{
							camRight = true;
							break;
						}
						case SDLK_RIGHT:
						{
							camLeft = true;
							break;
						}
						}
						break;
					case SDL_KEYUP:
						switch (incomingEvent.key.keysym.sym)
						{
						case SDLK_d:
						{
							cmdLeft = false;
							break;
						}
						case SDLK_a:
						{
							cmdRight = false;
							break;
						}
						case SDLK_UP:
						{
							camMoveForward = false;
							break;
						}
						case SDLK_DOWN:
						{
							camMoveBackwards = false;
							break;
						}
						case SDLK_LEFT:
						{
							camRight = false;
							break;
						}
						case SDLK_RIGHT:
						{
							camLeft = false;
							break;
						}
						}
						break;

					}

				}

				// calculate delta time
				unsigned int current = SDL_GetTicks();

				float deltaTs = (float)(current - lastTime) / 1000.0f;
				lastTime = current;


				// Create enemys depending on how far away the player is to the next object that has already been created
				if (lastCubeX - _player->getComponent<Transform>()->getPosition().x < 20)
				{
					std::cout << "New spawn" << std::endl;
					std::shared_ptr<Entity> en = self.lock()->addEntity();
					en->getProgram()->addEntity();
					std::shared_ptr<MeshRender> gmr = en->addComponent<Aspect::Engine::MeshRender>();
					gmr->setTexture("../Images/Please_give_me_70.png");
					en->addComponent<BoxCollider>();
					en->addComponent<Transform>();
					en->addComponent<Movement>();

					en->getComponent<Transform>()->Rotate(0.0f, 0.0f, 00.0f);
					en->getComponent<Transform>()->Translate(glm::vec3(lastCubeX + 3.0f, 0.0f, 0.0f));
					lastCubeX += 5;

				}

				//cause random block movement and they bounce off each box you cant see
				if (RandomX - _player->getComponent<Transform>()->getPosition().x < 25)
				{
					std::cout << "New Background" << std::endl;
					std::shared_ptr<Entity> bb = self.lock()->addEntity();
					bb->getProgram()->addEntity();
					std::shared_ptr<MeshRender> gmr = bb->addComponent<Aspect::Engine::MeshRender>();
					gmr->setTexture("../Images/Please_give_me_70.png");
					bb->addComponent<BoxCollider>();
					bb->addComponent<Transform>();
					bb->addComponent<Movement>();

					bb->getComponent<Transform>()->Rotate(180.0f, 90.0f, 0.0f);
					bb->getComponent<Transform>()->Translate(glm::vec3(lastCubeX + 3.0f, 0.0f, 0.0f));
					bb->getComponent<Transform>()->setScale(5, 5, 1);
					RandomX += 10;

				}

				// Create background depending on how far away the player is to the next object that has already been created
				if (backgroundX - _player->getComponent<Transform>()->getPosition().x < 25)
				{
					std::cout << "New Background" << std::endl;
					std::shared_ptr<Entity> bkg = self.lock()->addEntity();
					bkg->getProgram()->addEntity();
					std::shared_ptr<MeshRender> gmr = bkg->addComponent<Aspect::Engine::MeshRender>();
					gmr->setTexture("../Images/bkg.png");

					bkg->addComponent<Transform>();
					bkg->getComponent<Transform>()->Translate(glm::vec3(backgroundX + 5.0f, 0.0f, -10.0f));
					bkg->getComponent<Transform>()->setScale(7, 10, 1);
					backgroundX += 14;

				}

				// Score for the game, Controlls the camera speed depending on speed
				if (_player->getComponent<Transform>()->getPosition().x > lastCubeX - _player->getComponent<Transform>()->getPosition().x)
				{

					scoreTime++;
					if (scoreTime > 3) // slows down the increase of score
					{
						score++;
						scoreTime = 0;
					}
					std::cout << score << std::endl;
				}

				// Controls the camera pan speed
				if (score <= 100)
				{
					_cam->getComponent<Transform>()->Translate(0.04, 0.0, 0.0);
				}
				else if (score >= 150)
				{
					_cam->getComponent<Transform>()->Translate(0.09, 0.0, 0.0);
				}
				else if (score >= 200)
				{
					_cam->getComponent<Transform>()->Translate(0.12, 0.0, 0.0);
				}



				// Player movement
				if (cmdLeft & !cmdRight & !cmdMoveBackwards & !cmdMoveForward)
				{
					_player->getComponent<Aspect::Engine::Transform>()->Translate(10.0f*deltaTs, 0, 0);
				}
				if (cmdRight & !cmdLeft & !cmdMoveForward & !cmdMoveBackwards)
				{
					_player->getComponent <Aspect::Engine::Transform>()->Translate(-10.0f*deltaTs, 0, 0);
				}


				// Camera movement with arrow keys
				if (camMoveForward & !camMoveBackwards & !camLeft & !camRight)
				{
					_cam->getComponent<Aspect::Engine::Transform>()->Translate(0, 0, 10.0f*deltaTs);
				}
				if (camLeft & !cmdRight & !camMoveBackwards & !camMoveForward)
				{
					_cam->getComponent<Aspect::Engine::Transform>()->Translate(15.0f*deltaTs, 0, 0);
				}
				if (camRight & !camLeft & !camMoveForward & !camMoveBackwards)
				{
					_cam->getComponent <Aspect::Engine::Transform>()->Translate(-10.0f*deltaTs, 0, 0);
				}
				if (camMoveBackwards & !camMoveForward & !camLeft & !camRight)
				{
					_cam->getComponent<Aspect::Engine::Transform>()->Translate(0, 0, -10.0f*deltaTs);
				}



				// Collision checks, checking if any entity in the scene is colliding
				for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); it++) // Loop through all the entities
				{
					(*it)->count();	// Update them one at a time

					for (std::vector<std::shared_ptr<Entity> >::iterator it2 = entities.begin(); it2 != entities.end(); it2++)
					{
						if (*it == *it2 || (*it)->hasComponent<BoxCollider>() == false || (*it2)->hasComponent<BoxCollider>() == false)
						{
							continue;
						}
						else
						{
							(*it)->getComponent<BoxCollider>()->BoxCollision(*it2); // Send the entites to be checked
						}
					}

				}

				for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); it++) // Loop through all the entities again
				{
					if ((*it)->isDestroyed() == true)
					{
						(*it)->getComponent<MeshRender>()->MrEnable = false; // Turn the mesh renderer off
						(*it)->getComponent<BoxCollider>()->Hitbox = false; // Turn off the hit box (collider)
					}
				}



				glClearColor(0.0f, 0.0f, 0.0f, 1.0f);	// Set the background colour
				glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Clear the buffer

				std::vector <std::shared_ptr<Entity>> cameras;

				for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); it++) // Loop through all the entities
				{
					(*it)->count();	// Update them one at a time

					if ((*it)->hasComponent<Camera>() == true)
					{
						cameras.push_back(*it);
					}
				}

				for (std::vector<std::shared_ptr<Entity> >::iterator it = cameras.begin(); it != cameras.end(); it++) // Loop through all the entities again
				{
					setCurrentCamera((*it)->getComponent<Camera>());
					(*it)->display();	// Draw them
				}



				for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); it++) // Loop through all the entities again
				{
					(*it)->display();	// Draw them
				}


				SDL_GL_SwapWindow(_window);

				// Delta time
				if (deltaTs < (1.0f / 50.0f))
				{
					SDL_Delay((unsigned int)(((1.0f / 50.0f) - deltaTs)*1000.0f));
				}

			}

		}



		void Program::End()
		{
			//SDL_GL_DeleteContext(glcontext); // Delete context associated with the window
			running = false;
			SDL_DestroyWindow(_window);		 // Destory the window
			SDL_Quit();

		}

		std::shared_ptr<Entity> Program::addEntity()
		{
			std::shared_ptr<Entity> rtn = std::make_shared <Entity>(); // Creates a new entity
			entities.push_back(rtn); // Pushes it back into the entities list
			rtn->program = self.lock(); // Add it back to the program
			rtn->addComponent<Transform>(); // Add a trransform
			rtn->getComponent<Transform>()->setRotation(glm::vec3(0, 0, 0));			// Set 0 rotation
			rtn->getComponent<Transform>()->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));	// Set 0 position
			rtn->getComponent<Transform>()->setScale(1.0f, 1.0f, 1.0f);					// Set scale to 1
	
			
			rtn->self = rtn;
			
			//rtn->program = rtn;

			
			return rtn;
		}

		void Program::setCurrentCamera(std::shared_ptr<Camera> cam)	// Set the current camera to be the cam
		{
			currentCam = cam;
		}

		std::shared_ptr<Camera> Program::getCurrentCamera() // Get the current camera
		{
			return currentCam.lock();
		}



	}

}