/// @Entity.cpp
/// @Creates the entities that are game objects

// Program Includes
#include "Entity.h" 
#include "Component.h"

// System Includes
#include <iostream>

namespace Aspect
{
	namespace Engine
	{
		std::shared_ptr<Program> Entity::getProgram()	// Get program function to access count and display
		{

			return program.lock();
		}

		void Entity::count()	// Update Function for each entity
		{
			for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin(); // Go through the list
				it != components.end(); it++)												 // If its not the end continue
			{
				if (!(*it)->m_begin)		// If its not the begin
				{
					(*it)->onBegin();		// Make that the start
					(*it)->m_begin = true;	// Set its began to true
				}

				(*it)->onCount();	// Update current
			}
		}

		void Entity::display() // Draw
		{
			for (std::vector<std::shared_ptr<Component> >::iterator it = components.begin(); // Go through the list
				it != components.end(); it++)												 // If its not the end continue
			{
				(*it)->onDisplay();		// Draw to the screen
			}
		}
	}
}