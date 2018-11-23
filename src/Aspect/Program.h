#include <SDL.h>	// Include SDL
#include <AL/al.h>	// Include the audio extention
#include <AL/alc.h> // Include audio extentions
#include <memory>	// Include memory for shared_ptr
#include <vector>	// Include vector for the use of vectors


#ifndef ASPECT_ENGINE_PROGRAM_H
#define ASPECT_ENGINE_PROGRAM_H


namespace Aspect	// Namespace 1
{
	namespace Engine // Namespace 2
	{
		class Entity; /// Initialise the entity class
		class Camera; /// Initialise the camera class
		
		extern SDL_Renderer *_renderer;  // Allows access to renderer in other files

		class Program /// Program class the main class that oganises the program
		{
		public:
		
			void Start(std::shared_ptr<Entity> _cam, std::shared_ptr<Entity> _player);	/// Start the program, also contains the game loop
			void End();			/// Clean up and close the program
			static bool InitGlew();		/// Initialise Glew
			static std::shared_ptr<Program> InitSDL();	/// Initialise SDL
			static std::shared_ptr<Entity> addEntity();	/// Add entity function
			void setCurrentCamera(std::shared_ptr<Camera> cam); /// Set the current camera
			std::shared_ptr<Camera> getCurrentCamera();	/// Get the location and martix of the current camera
			
			
			float lastCubeX = -6.0f; // last cube x distance
			float RandomX = -10.0f;	// Random distance for enemy
			float backgroundX = -10.0f; // Background spawn distance
			bool running;	// Bool to tell if the program is running or not

		private:
			
			static std::vector<std::shared_ptr<Entity> > entities; // List of entities of class entity
			
			static std::weak_ptr<Program> self;	// Pointer to itself
			static SDL_Window *_window;		// Pointer window for SDL set up
			ALCdevice* device;	// Device 
			ALCcontext* context; // Context
			std::weak_ptr<Camera> currentCam; // Pointer to the current cam

		protected:
			static glm::mat4 modelMatrix; // Model matrix used within mesh renderer
		};
		
	}

}

#endif _ASPECT_ENGINE_PROGRAM_H

