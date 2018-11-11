#include <iostream>
#include <memory>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <SDL.h>


#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"

namespace Aspect
{
	namespace Engine
	{
		class BoxCollider;

		void BoxCollider::BoxCollision(std::shared_ptr<Entity> _object)
		{
			if (getEntity() == getEntity())
			{
				return;
			}

			if (getEntity()->getComponent<Transform>()->getPosition().x <= (_object->getComponent<Transform>()->getPosition().x + _object->getComponent<Transform>()->getScale().x / 1)
				&& getEntity()->getComponent<Transform>()->getPosition().x >= (_object->getComponent<Transform>()->getPosition().x - _object->getComponent<Transform>()->getScale().x / 1))
			{
				if (getEntity()->getComponent<Transform>()->getPosition().y <= (_object->getComponent<Transform>()->getPosition().y + _object->getComponent<Transform>()->getScale().y / 1)
					&& getEntity()->getComponent<Transform>()->getPosition().y >= (_object->getComponent<Transform>()->getPosition().y - _object->getComponent<Transform>()->getScale().y / 1))
				{
					if (getEntity()->getComponent<Transform>()->getPosition().z <= (_object->getComponent<Transform>()->getPosition().z + _object->getComponent<Transform>()->getScale().z / 1)
						&& getEntity()->getComponent<Transform>()->getPosition().z >= (_object->getComponent<Transform>()->getPosition().z - _object->getComponent<Transform>()->getScale().z / 1))
					{

						std::cout << "hit" << std::endl;

					}
				}
			}
		}

	}
}