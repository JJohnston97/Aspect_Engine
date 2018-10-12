#include "Entity.h"
#include <iostream>
#include "Component.h"

namespace Aspect
{
	namespace Engine
	{

		Entity::Entity()
		{



		}

		Entity::~Entity()
		{

			// Trying to push
		}

		void Entity::addEntity()
		{


			// Template Type T?


		}

		std::shared_ptr<Program> Entity::getProgram()
		{

			return program.lock();
		}

		void Entity::count()
		{
			for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin();
				it != components.end(); it++)
			{
				if (!(*it)->began)
				{
					(*it)->onBegin();
					(*it)->began = true;
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