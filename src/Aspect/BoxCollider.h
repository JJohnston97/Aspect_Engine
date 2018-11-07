#include <iostream>
#include <memory>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <SDL.h>

#include "Component.h"

namespace Aspect
{
	namespace Engine
	{
		class BoxCollider : public Component
		{
		public:
			void BoxCollision(std::shared_ptr<Entity> _object);



		};

	}
}