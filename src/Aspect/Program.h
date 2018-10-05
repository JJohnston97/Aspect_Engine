#ifndef ASPECT_ENGINE_PROGRAM_H
#define ASPECT_ENGINE_PROGRAM_H

#include <SDL.h>
#include "SDL.h"

namespace Aspect
{
	namespace Engine
	{
		extern SDL_Renderer *_renderer;  // Allows access to renderer in other files
		
		bool InitGlew();		// Initialise Glew

		bool InitSDL();			// Initialise SDL

	}

}








#endif 

