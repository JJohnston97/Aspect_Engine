#include "Entity.h" // Include Entity.h
#include <iostream>
#include "Component.h"

namespace Aspect
{
	namespace Engine
	{
		std::shared_ptr<Program> Entity::getProgram()
		{

			return program.lock();
		}

		void Entity::count()
		{
			for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
				it != components.end(); it++)
			{
				if (!(*it)->m_begin)
				{
					(*it)->onBegin();
					(*it)->m_begin = true;
				}

				(*it)->onCount();
			}
		}

		void Entity::display()
		{
			for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
				it != components.end(); it++)
			{
				(*it)->onDisplay();
			}
		}
	}
}