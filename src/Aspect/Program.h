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
		
			void Start();
			void End();
			static bool InitGlew();		// Initialise Glew
			static std::shared_ptr<Program> InitSDL();			// Initialise SDL
			static std::shared_ptr<Entity> addEntity();

		private:
		
			bool running;
			std::vector<std::shared_ptr<Entity> > entities;
			std::weak_ptr<Program> self;
			static SDL_Window *_window;
		};
		
	}

}








#endif 

