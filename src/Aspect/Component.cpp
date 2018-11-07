#include "Component.h"
#include <iostream>
#include "Entity.h"

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
			//model matrix = glm::scale 
		}
		void Component::onDisplay()
		{

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