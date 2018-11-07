#include <iostream>
#include <memory>
#include <windows.h>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <SDL.h>

#include "Component.h"


namespace Aspect
{
	namespace Engine
	{
		class Transform : public Component
		{
		public:

			Transform();
			void Translate(float x, float y, float z);
			void Translate(const glm::vec3 &dir);
			void setPosition(glm::vec3 &pos);
			void Rotate(float x, float y, float z);
			void Rotate(const glm::vec3 &dir);
			void setRotation(const glm::vec3 &rot);
			//void setScale(const glm::vec3 &size);
			//void Scale(float x, float y, float z);

			glm::mat4 getModelMatrix();

			

			glm::mat4 getOrientation();
			glm::mat4 getTranslation();
		

			glm::vec3 getScale() { return scale; }
			glm::vec3 getPosition() { return position; }
			glm::vec3 getRotation() { return rotation; }

			void setScale(float scaleX, float scaleY, float scaleZ) { scale.x = scaleX; scale.y = scaleY; scale.z = scaleZ; }


		private:

			glm::vec3 position;
			glm::vec3 rotation;
			glm::vec3 scale;
			glm::mat4 translation;
			glm::mat4 orientation;


		};
	}
}