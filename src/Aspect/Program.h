#ifndef ASPECT_ENGINE_PROGRAM_H
#define ASPECT_ENGINE_PROGRAM_H

#include <SDL.h>

#include <memory>

namespace Aspect
{
	namespace Engine
	{
		class Entity;
		extern SDL_Renderer *_renderer;  // Allows access to renderer in other files

		class Program
		{
		public:
		
		static bool InitGlew();		// Initialise Glew

		static std::shared_ptr<Program> InitSDL();			// Initialise SDL
		static std::shared_ptr<Entity> addEntity();

		bool running;

		};
		
	}

}








#endif 

