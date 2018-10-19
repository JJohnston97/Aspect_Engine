#ifndef ASPECT_ENGINE_PROGRAM_H
#define ASPECT_ENGINE_PROGRAM_H

#include <SDL.h>

#include <memory>
#include <vector>

namespace Aspect
{
	namespace Engine
	{
		class Entity;
		extern SDL_Renderer *_renderer;  // Allows access to renderer in other files

		class Program
		{
		public:
		
			void Start();		// Start the program, also contains the game loop
			void End();			// Clean up and close the program
			static bool InitGlew();		// Initialise Glew
			static std::shared_ptr<Program> InitSDL();	// Initialise SDL
			static std::shared_ptr<Entity> addEntity();	// Add entity function

		private:
			
			bool running;	// Bool to tell if the program is running or not
			static std::vector<std::shared_ptr<Entity> > entities; // List of entities of class entity
			std::weak_ptr<Program> self;	// Pointer to itself
			static SDL_Window *_window;		// Pointer window for SDL set up
		};
		
	}

}








#endif 

