#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>
#include <GLM/gtc/type_ptr.hpp>
#include <GLM/gtc/matrix_transform.hpp>

#include "Camera.h"
#include "Transform.h"

namespace Aspect
{
	namespace Engine
	{
		void Camera::onInit()
		{



		}

		glm::mat4 Camera::getProjectionMatrix()
		{
			return glm::perspective(glm::radians(45.0f),
				(float)1080 / (float)900, 0.1f, 100.f);

		
		}
	



	}
}
