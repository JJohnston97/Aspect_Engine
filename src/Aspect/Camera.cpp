/// @Camera.ccp
/// @Controls the camera class

// System Includes
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <GLM/gtc/type_ptr.hpp>
#include <GLM/gtc/matrix_transform.hpp>

// Project Includes
#include "Camera.h"
#include "Transform.h"

namespace Aspect
{
	namespace Engine
	{
		void Camera::onInit()	// Camera init function
		{		

		}

		glm::mat4 Camera::getProjectionMatrix()	// Get the projection matrix (Location of the revse movements of the entity its looking at)
		{
			return glm::perspective(glm::radians(45.0f),
				(float)1080 / (float)900, 0.1f, 100.f);

		
		}
	



	}
}
