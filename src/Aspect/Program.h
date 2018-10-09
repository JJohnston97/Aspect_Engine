#ifndef ASPECT_ENGINE_PROGRAM_H
#define ASPECT_ENGINE_PROGRAM_H

#include <SDL.h>
#include "SDL.h"
#include "Screen.h"

namespace Aspect
{
	namespace Engine
	{
		extern SDL_Renderer *_renderer;  // Allows access to renderer in other files
		
		bool InitGlew();		// Initialise Glew

		std::shared_ptr<Scene> InitSDL();			// Initialise SDL
		
	}

}








#endif 

