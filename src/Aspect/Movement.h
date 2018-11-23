#include <iostream> // Iostream for the use of cout for debug
#include <memory>   // Include for use of shared_ptr
#include <GL/glew.h> // Include glew
#include <glm/glm.hpp>	// Include GLM
#include <SDL.h>	// Include sdl

#include "Component.h" // Include Component header 

#ifndef _MOVEMENT_H_
#define _MOVEMENT_H_

namespace Aspect		// Namespace 1
{
	namespace Engine    // Namespace 2
	{
		class Movement : public Component  /// Movement class used to add a constant movement to the enemys
		{
		public:

			Movement();  /// Constructor for movement

			void onCount() override; /// Overrides the update function and uses its own to apply transform to the objects

			float velSlow = 0.1f; // float for velocity
			float velFast = 0.3f; // float for velocity

		};
	}
}
#endif // !_MOVEMENT_H_