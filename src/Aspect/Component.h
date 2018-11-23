#include <iostream> // Inialise use for debug and writing to the console
#include <string>	// Allows for the use of string
#include <vector>	// Allows for the use of vectors
#include <memory>	// Allows for the use of smart and weak pointers
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp> // This one lets us use matrix transformations
#include <GLM/gtc/type_ptr.hpp>			// This one gives us access to a utility function which makes sending data to OpenGL nice and easy
#include <GLM/gtc/quaternion.hpp>

#ifndef _COMPONENT_H_
#define _COMPONENT_H_

namespace Aspect		// Name space 1
{
	namespace Engine	// Name space 2
	{
		class Entity;	/// Initialise Entity class rather than include
		class Program;	/// Initialise Program class rather than include

		class Component	/// Component class
		{
			friend class Entity;	// Entity is a friend class so it has the right to access all
									// private and protected memebers of the class
		public:
			virtual ~Component();	/// Class distructor
			std::shared_ptr<Program> getProgram(); /// Creates a shared ptr function getProgram
			std::shared_ptr<Entity> getEntity();   /// Creates a shared ptr function to getEntiy
			void addEntity(std::weak_ptr<Entity> _entity); /// Creates the add entity function to add more entites to the program and entities list
			

		private:
			std::weak_ptr<Entity> entity;	// Weak pointer to entity to keep a cache of recently accessed objects
			bool m_begin;					// Use for yes or no for begin of entity vectors
			glm::mat4 viewMatrix;
			float cameraAngleX, cameraAngleY;

			virtual void onInit();		/// Initialise component function
			virtual void onBegin();		/// Begin function for components for entities
			virtual void onCount();		/// On count same as update
			virtual void onDisplay();	/// On display is draw


		

		protected:

		};
	}
}

#endif // _COMPONENT_H_