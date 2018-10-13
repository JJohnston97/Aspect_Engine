#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

#include "Program.h"
#include "Entity.h"


namespace Aspect
{
	namespace Engine
	{
		SDL_Window *Program::_window;

		bool Program::InitGlew()
		{
			glewExperimental = GL_TRUE; // Enable Glew Experimental features

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
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);	// Using 4.3 OpenGL Major part 4
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);	// Minor part 3
			SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE); // Using the latest version

			int windowPositionX = 100;	// Window position (Needs to change from this)
			int winowPositionY = 100;	// Window Y pos
			int windowWidth = 1080;
			int windowHeight = 900;

			_window = SDL_CreateWindow("Aspect Engine", windowPositionX, winowPositionY, windowWidth, windowHeight, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);	// Creates the SDL/OpenGL window
			SDL_Renderer * renderer = SDL_CreateRenderer(_window, -1, 0);	// Creates the render, needs to between -1 and 0
			SDL_GLContext glcontext = SDL_GL_CreateContext(_window);			// Returns the OpenGl context associated with window

			if (!Program::InitGlew())	// If glew has not been initialised
			{
				return false;		// Close the program
			}

			unsigned int lastTime = SDL_GetTicks();	// Used to work out time between frame

			glEnable(GL_DEPTH_TEST);	// Used to make sure what is in front are alwasy in front no matter the order they are drawn


			unsigned int current = SDL_GetTicks();					 // Get the current time since SDL was initialised
			float deltaTs = (float)(current - lastTime) / 1000.0f;   // Time from current take away time from last divied by 1000 as its in miliseconds
			lastTime = current;										 // Current fame is next frames last time


			// Draw world
			//std::cout << "Where I would call game function" << std::endl;

			glClearColor(1.0f, 0.0f, 0.0f, 0.0f);			    // Colour of background
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Write the colour to the framebuffer

			SDL_GL_SwapWindow(_window);	// Tells the renderer to show it contect to the screen


			if (deltaTs < (1.0f / 50.0f))	// Limiter to 50fps incase running to quickly
			{
				SDL_Delay((unsigned int)(((1.0f / 50.0f) - deltaTs)*1000.0f));
			}
			//}

			std::shared_ptr<Program> rtn = std::make_shared<Program>();


			SDL_GL_DeleteContext(glcontext); // Delete context associated with the window
			SDL_DestroyWindow(_window);		 // Destory the window
			SDL_Quit();						 // Close SDL


			return rtn;			// return rtn when set up
			
		}

		void Program::Start()
		{
			running = true;

			while (running)
			{
				SDL_Event incomingEvent;				
				while (SDL_PollEvent(&incomingEvent))	// Check if there is an event in the queue
				{
					switch (incomingEvent.type)			// If there is an event will return true and will fill the incoming event
					{									// Switch is based on the event type
					case SDL_QUIT:						// If the event type is quit
					running = false;					// End the program
					break;								

					}
				}


				for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); it++)
				{
					(*it)->count();
				}

				glClearColor(0.0f, 0.0f, 0.3f, 1.0f);
				glClear(GL_COLOR_BUFFER_BIT);

				for (std::vector<std::shared_ptr<Entity> >::iterator it = entities.begin(); it != entities.end(); it++)
				{
					(*it)->display();
				}

				SDL_GL_SwapWindow(_window);



			}

		}

		void Program::End()
		{

			running = false;

		}


		std::shared_ptr<Entity> Program::addEntity()
		{
			std::shared_ptr<Entity> rtn = std::make_shared <Entity>();
			//entities.pushback(rtn);
			return rtn;
		}

	}

}