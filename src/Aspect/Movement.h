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
		class Movement : public Component
		{
		public:

			Movement();

			void onCount() override;

			float velSlow = 0.1f;
			float velFast = 0.3f;

		};

	}

}