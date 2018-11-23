#include <iostream>		// Iostream for the use of cout for debug
#include <memory>		// Include for use of shared_ptr
#include <windows.h>	// Include window for time
#include <GL/glew.h>	// Include glew
#include <glm/glm.hpp>  // Include glm
#include <SDL.h>		// Include SDL

#include "Component.h" // Include the component header

#ifndef _TRANSFORM_H_
#define _TRANSFORM_H_

namespace Aspect // Namespace 1
{
	namespace Engine	// Namespace 2
	{
		class Transform : public Component  /// Transform class allows the use of translate, rotate and scale for game objects, added to every entity when created
		{
		public:

			Transform();/// Transform constructor
			void Translate(float x, float y, float z); /// Translate function allows to move the game objects 
			void Translate(const glm::vec3 &dir);	   /// Translate that takes a glm vec3 rather than three float variables
			void setPosition(glm::vec3 &pos);		   /// Set position function to take a glm vec 3 and set the new position to the pass in vec
			void Rotate(float x, float y, float z);	   /// Rotate function taking 3 floats
			void Rotate(const glm::vec3 &dir);		   /// Rotate takes a glm vec 3
			void setRotation(const glm::vec3 &rot);	   /// Set position for when an object is first created
			void setScale(float scaleX, float scaleY, float scaleZ) { scale.x = scaleX; scale.y = scaleY; scale.z = scaleZ; } /// Set scale of the object, set to 1,1,1 on create
			
			void onCount() override;	/// Allows use of an overriden update function
			float vel = 0.1f;	// velocity is 0.1


			glm::mat4 getModelMatrix(); /// Mat4 return of the model matrix
			glm::mat4 getViewMatrix();	/// Mat4 return of view matrix
			glm::mat4 getOrientation();	/// Mat4 get orientation of the object
		
			glm::vec3 getScale() { return scale; }			/// Get the scale of the object
			glm::vec3 getPosition() { return position; }	/// Get the position of the object
			glm::vec3 getRotation() { return rotation; }	/// Get the rotation of the object



		private:

			float cameraAngleX, cameraAngleY; // Camera angles

			glm::vec3 position;	// Vec3 of position	
			glm::vec3 rotation;	// Vec3 of rotation
			glm::vec3 scale;	// Vec3 of scale
			
			glm::mat4 translation; // Mat4 for translation
			glm::mat4 orientation; // Mat4 for orientation
			glm::mat4 modelMatrix; // Mat4 for model matrix
			glm::mat4 rotMatrix;   // Mat4 for rotation matrix
			glm::mat4 viewMatrix;  // Mat4 for view matrix
			
			glm::quat cameraOrientation; // quat for camera Orientation


		};
	}
}
#endif // !_TRANSFORM_H_