#include <iostream>
#include <memory>
#include <windows.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <SDL.h>
#include "Transform.h"

namespace Aspect
{
	namespace Engine
	{
		class Transform;

		Transform::Transform()
		{
			scale = glm::vec3(1, 1, 1);
		}

		void Transform::Translate(float x, float y, float z)
		{
			position += glm::vec3(x, y, z);
		}

		void Transform::Translate(const glm::vec3 & dir)
		{
			position += dir;
		}

		glm::mat4 Transform::getModelMatrix()
		{
			//glm::scale(glm::translate(glm::mat4(1.0f), position), scale);
			return glm::translate(glm::mat4(1.0f), position);
		}

		void Transform::setPosition(glm::vec3 &pos)
		{
			position = pos;
		}

		void Transform::Rotate(float x, float y, float z)
		{
			rotation += glm::vec3(x, y, z);
		}

		void Transform::Rotate(const glm::vec3 &dir)
		{
			rotation += dir;
		}

		void Transform::setRotation(const glm::vec3 &rot)
		{

		}

		glm::mat4 Transform::getOrientation()
		{
			orientation = glm::rotate(orientation, rotation.x, glm::vec3(1, 0, 0));
			orientation = glm::rotate(orientation, rotation.y, glm::vec3(0, 1, 0));
			orientation = glm::rotate(orientation, rotation.z, glm::vec3(0, 0, 1));

			return orientation;
		}

		glm::mat4 Transform::getTranslation()
		{
			//translation = glm::translate(position.x, position.y, position.z);
			return translation;
		}



	}

}