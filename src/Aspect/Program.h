#ifndef ASPECT_ENGINE_PROGRAM_H
#define ASPECT_ENGINE_PROGRAM_H

#include <SDL.h>
#include <AL/al.h>
#include <AL/alc.h>


#include <memory>
#include <vector>

namespace Aspect
{
	namespace Engine
	{
		class Entity;
		class Camera;
		extern SDL_Renderer *_renderer;  // Allows access to renderer in other files

		class Program
		{
		public:
		
			void Start(std::shared_ptr<Entity> _cam, std::shared_ptr<Entity> _player);		// Start the program, also contains the game loop
			void End();			// Clean up and close the program
			static bool InitGlew();		// Initialise Glew
			static std::shared_ptr<Program> InitSDL();	// Initialise SDL
			static std::shared_ptr<Entity> addEntity();	// Add entity function
			void setCurrentCamera(std::shared_ptr<Camera> cam);
			std::shared_ptr<Camera> getCurrentCamera();
			float lastCubeX = -6.0f;
			float RandomX = -10.0f;
			float backgroundX = -10.0f;
			bool running;	// Bool to tell if the program is running or not

		private:
			
			static std::vector<std::shared_ptr<Entity> > entities; // List of entities of class entity
			
			static std::weak_ptr<Program> self;	// Pointer to itself
			static SDL_Window *_window;		// Pointer window for SDL set up
			ALCdevice* device;
			ALCcontext* context;
			std::weak_ptr<Camera> currentCam;

		protected:
			static glm::mat4 modelMatrix;
		};
		
	}

}








#endif 

