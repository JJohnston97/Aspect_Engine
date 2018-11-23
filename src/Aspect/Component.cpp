/// @Component.cpp
/// @Component class holds each time of component that are added to each entity

// System Includes
#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>

// Project Includes
#include "Entity.h"
#include "Component.h"
#include "Transform.h"

namespace Aspect
{
	namespace Engine
	{  
		// All functions that are here have override function in other classes
		Component::~Component() 
		{
		


		}
		void Component::onInit()
		{



		}
		void Component::onBegin()
		{
			


		}
		void Component::onCount()
		{
			

		}
		void Component::onDisplay()
		{



		}

		// Adds entity
		void Component::addEntity(std::weak_ptr<Entity> _entity)
		{
			entity = _entity;
		}

		// Get entity's component
		std::shared_ptr<Entity> Component::getEntity()
		{
			return entity.lock();
		}

		// Get the project from the entity
		std::shared_ptr<Program> Component::getProgram()
		{
			return getEntity()->getProgram();
		}
	 
	}
}