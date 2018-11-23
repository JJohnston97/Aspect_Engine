// System includes
#include <iostream>
#include <memory>
#include <windows.h>
#include <GL/glew.h>

#define GLM_FORCE_CTOR_INIT
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <SDL.h>

// Project Includes
#include "Transform.h"
#include "Entity.h"


namespace Aspect
{
	namespace Engine
	{
		class Transform; // Forward declarations of Transform
		
		// Transform constructor
		Transform::Transform()
		{
			scale = glm::vec3(1, 1, 1);
		}
		
		// Translate the position with floats
		void Transform::Translate(float x, float y, float z)
		{
			position += glm::vec3(x, y, z);
		}

		// Translate the object position
		void Transform::Translate(const glm::vec3 & dir)
		{
			position += dir;
		}

		void Transform::onCount()
		{
			

		}

		// Calculate the model matrix 
		glm::mat4 Transform::getModelMatrix()
		{
			while (rotation.y > (3.14159265358979323846 * 2.0))
			{
				rotation.y -= (float)(3.14159265358979323846 * 2.0);
			}
		
			
			rotMatrix = glm::rotate(glm::mat4(1.0f), rotation.y, glm::vec3(0, 1, 0));
			rotMatrix = glm::rotate(rotMatrix, rotation.x, glm::vec3(1, 0, 0));
			rotMatrix = glm::rotate(rotMatrix, rotation.z, glm::vec3(0, 0, 1));
			

			modelMatrix = glm::translate(glm::mat4(1.0f), position) * rotMatrix * glm::scale(glm::mat4(1), scale);

			return modelMatrix;
		}


		// Calculates the view matirx
		glm::mat4 Transform::getViewMatrix()
		{
			return glm::inverse(getModelMatrix());
		}


		// Set the position with a GLM ::vec3
		void Transform::setPosition(glm::vec3 &pos)
		{
			position = pos;
		}

		// Rotate the object with floats
		void Transform::Rotate(float x, float y, float z)
		{
			rotation += glm::vec3(x, y, z);
		}

		// Rotate the object with GLM::vec3
		void Transform::Rotate(const glm::vec3 &dir)
		{
			rotation += dir;
		}

		// Set the rotation
		void Transform::setRotation(const glm::vec3 &rot)
		{
			rotation = rot;
		}


		// Get the orientation of the object
		glm::mat4 Transform::getOrientation()
		{
			orientation = glm::rotate(orientation, rotation.x, glm::vec3(1, 0, 0));
			orientation = glm::rotate(orientation, rotation.y, glm::vec3(0, 1, 0));
			orientation = glm::rotate(orientation, rotation.z, glm::vec3(0, 0, 1));

			return orientation;
		}

	}

}