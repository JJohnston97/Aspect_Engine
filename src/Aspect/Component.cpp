#include "Component.h"
#include <iostream>
#include "Entity.h"
#include "Transform.h"
#include <GL/glew.h>
#include <glm/glm.hpp>

namespace Aspect
{
	namespace Engine
	{  
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
		void Component::addEntity(std::weak_ptr<Entity> _entity)
		{
			entity = _entity;
		}
		std::shared_ptr<Entity> Component::getEntity()
		{
			return entity.lock();
		}

		std::shared_ptr<Program> Component::getProgram()
		{
			return getEntity()->getProgram();
		}
	 
	}
}