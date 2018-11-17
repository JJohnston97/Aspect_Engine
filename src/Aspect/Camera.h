#include <vector>
#include <memory>

#include "Component.h"

namespace Aspect
{
	namespace Engine
	{
		class Camera : public Component
		{
		public:
			
			void onInit();

			glm::mat4 getProjectionMatrix();


		};

	}

}