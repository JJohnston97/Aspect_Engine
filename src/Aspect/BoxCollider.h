#include <iostream>    // Include iosteam for debugging
#include <memory>	   // Include Memory for shared_ptr
#include <GL/glew.h>   // Glew include
#include <glm/glm.hpp> // Include GLM
#include <SDL.h>	   // SDL include
#include "Component.h" // Include Component header

namespace Aspect // Aspect namespace
{
	namespace Engine // Aspect namespace
	{
		class BoxCollider : public Component		/// Box collide class, inherits from component
		{
		public:
			void BoxCollision(std::shared_ptr<Entity> _object);  /// Box collision check function
			bool Hitbox = true;									 /// Hit Box enable / disable


		};

	}
}