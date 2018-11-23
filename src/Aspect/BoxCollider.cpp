/// @File BoxCollider.cpp
/// @Handles collision, box collision

// System Includes
#include <iostream>
#include <memory>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <SDL.h>

// Project Includes
#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"
#include "MeshRender.h"

namespace Aspect
{
	namespace Engine
	{
		class BoxCollider; // Initilise the box collider class 
		

		void BoxCollider::BoxCollision(std::shared_ptr<Entity> _object) // Checking if a collision is happening by adding box around the shape
		{
			if (Hitbox == true) // If the shape has a box collider and its hit box
			{
				// Get the entity and check if its x position is great than or equal to the other object position + 0/.7 of itself around the edge
				if (getEntity()->getComponent<Transform>()->getPosition().x <= (_object->getComponent<Transform>()->getPosition().x + _object->getComponent<Transform>()->getScale().x / 0.7f)
					&& getEntity()->getComponent<Transform>()->getPosition().x >= (_object->getComponent<Transform>()->getPosition().x - _object->getComponent<Transform>()->getScale().x / 0.7f))
				{
					// Get the entity and check if its y position is great than or equal to the other object position + 0/.7 of itself around the edge
					if (getEntity()->getComponent<Transform>()->getPosition().y <= (_object->getComponent<Transform>()->getPosition().y + _object->getComponent<Transform>()->getScale().y / 0.7f)
						&& getEntity()->getComponent<Transform>()->getPosition().y >= (_object->getComponent<Transform>()->getPosition().y - _object->getComponent<Transform>()->getScale().y / 0.7f))
					{
						// Get the entity and check if its z position is great than or equal to the other object position + 0/.7 of itself around the edge
						if (getEntity()->getComponent<Transform>()->getPosition().z <= (_object->getComponent<Transform>()->getPosition().z + _object->getComponent<Transform>()->getScale().z / 0.7f)
							&& getEntity()->getComponent<Transform>()->getPosition().z >= (_object->getComponent<Transform>()->getPosition().z - _object->getComponent<Transform>()->getScale().z / 0.7f))
						{
							getEntity()->getComponent<Transform>()->vel = -getEntity()->getComponent<Transform>()->vel; // Transformt the object velocity
							_object->setDestroy(true);	// Destory the object set it to be try

						}
					}
				}
			}
		}

	}
}