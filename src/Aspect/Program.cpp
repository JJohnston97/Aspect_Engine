#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <GLM/gtc/type_ptr.hpp>
#include <GLM/gtc/matrix_transform.hpp>

#include "Program.h"
#include "Entity.h"
#include "ShaderProgram.h"
#include "MeshRender.h"
#include "Transform.h"
#include "BoxCollider.h"
#include "Camera.h"
#include "Audio.h"

namespace Aspect
{
	namespace Engine
	{
		std::vector<std::shared_ptr<Entity> > Program::entities;

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

		void Program::Start(std::shared_ptr<Entity> _cam, std::shared_ptr<Entity> _player)
		{
			running = true;

			unsigned int lastTime = SDL_GetTicks();	// Used to work out time between frame
			bool cmdMoveForward = false, cmdMoveBackwards = false, cmdLeft = false, cmdRight = false;
			bool camMoveForward = false, camMoveBackwards = false, camLeft = false, camRight = false;

			float vel = -0.1f;
			
			std::shared_ptr<Aspect::Engine::Audio> ac = std::make_shared<Aspect::Engine::Audio>("../Contrib/Game_Music.ogg");
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
						case SDLK_s:
						{
							cmdMoveForward = true;
							break;
						}
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
						case SDLK_w:
						{
							cmdMoveBackwards = true;
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
							camLeft = true;
							break;
						}
						case SDLK_RIGHT:
						{
							camRight = true;
							break;
						}
						}
						break;
					case SDL_KEYUP:
						switch (incomingEvent.key.keysym.sym)
						{
						case SDLK_s:
						{
							cmdMoveForward = false;
							break;
						}
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
						case SDLK_w:
						{
							cmdMoveBackwards = false;
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
							camLeft = false;
							break;
						}
						case SDLK_RIGHT:
						{
							camRight = false;
							break;
						}
						}
						break;
					
					}
					
				}

				unsigned int current = SDL_GetTicks();

				float deltaTs = (float)(current - lastTime) / 1000.0f;
				lastTime - current;
				
				

				// Player movement
				if (cmdMoveForward & !cmdMoveBackwards & !cmdLeft & !cmdRight)
				{
					_player->getComponent<Aspect::Engine::Transform>()->Translate(0, 0, 0.1 * deltaTs);
				}
				if (cmdLeft & !cmdRight & !cmdMoveBackwards & !cmdMoveForward)
				{
					_player->getComponent<Aspect::Engine::Transform>()->Translate(0.1 * deltaTs, 0, 0);
				}
				if (cmdRight & !cmdLeft & !cmdMoveForward & !cmdMoveBackwards)
				{
					_player->getComponent <Aspect::Engine::Transform>()->Translate(-0.1 * deltaTs, 0, 0);
				}
				if (cmdMoveBackwards & !cmdMoveForward & !cmdLeft & !cmdRight)
				{
					_player->getComponent<Aspect::Engine::Transform>()->Translate(0, 0, -0.1 * deltaTs);
				}

				// Camera movement with arrow keys
				if (camMoveForward & !camMoveBackwards & !camLeft & !camRight)
				{
					_cam->getComponent<Aspect::Engine::Transform>()->Translate(0, 0, 0.1 * deltaTs);
				}
				if (camLeft & !cmdRight & !camMoveBackwards & !camMoveForward)
				{
					_cam->getComponent<Aspect::Engine::Transform>()->Translate(0.1 * deltaTs, 0, 0);
				}
				if (camRight & !camLeft & !camMoveForward & !camMoveBackwards)
				{
					_cam->getComponent <Aspect::Engine::Transform>()->Translate(-0.1 * deltaTs, 0, 0);
				}
				if (camMoveBackwards & !camMoveForward & !camLeft & !camRight)
				{
					_cam->getComponent<Aspect::Engine::Transform>()->Translate(0, 0, -0.1 * deltaTs);
				}

				entities[0]->getComponent<Transform>()->Translate(0, vel, 0);

				std::cout << entities[0]->getComponent<Transform>()->getPosition().y << std::endl;
				

				if ((entities[0]->getComponent<Transform>()->getPosition().y <= -9.0f))
				{
					//entities[0]->getComponent<MeshRender>()->MrEnable = false;
					vel = -vel;
				}
				if ((entities[0]->getComponent<Transform>()->getPosition().y >= 9.0f))
				{
					//entities[0]->getComponent<MeshRender>()->MrEnable = false;
					vel = -vel;
				}


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
							(*it)->getComponent<BoxCollider>()->BoxCollision(*it2);
						}
					}
					
				}

				for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); it++) // Loop through all the entities again
				{
					if ((*it)->isDestroyed() == true)
					{
						(*it)->getComponent<MeshRender>()->MrEnable = false;
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
			std::shared_ptr<Entity> rtn = std::make_shared <Entity>();
			entities.push_back(rtn);
			rtn->program = self.lock();
			rtn->addComponent<Transform>();
			rtn->getComponent<Transform>()->setRotation(glm::vec3(0, 0, 0));
			rtn->getComponent<Transform>()->setPosition(glm::vec3(0.0f, 0.0f, 0.0f));
			rtn->getComponent<Transform>()->setScale(1.0f, 1.0f, 1.0f);
	
			
			rtn->self = rtn;
			
			//rtn->program = rtn;

			
			return rtn;
		}

		void Program::setCurrentCamera(std::shared_ptr<Camera> cam)
		{
			currentCam = cam;
		}

		std::shared_ptr<Camera> Program::getCurrentCamera()
		{
			return currentCam.lock();
		}


	}

}