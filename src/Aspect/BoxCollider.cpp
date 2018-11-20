#include <iostream>
#include <memory>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <SDL.h>


#include "BoxCollider.h"
#include "Entity.h"
#include "Transform.h"
#include "MeshRender.h"

namespace Aspect
{
	namespace Engine
	{
		class BoxCollider;
		

		void BoxCollider::BoxCollision(std::shared_ptr<Entity> _object)
		{
			if (Hitbox == true)
			{
				if (getEntity()->getComponent<Transform>()->getPosition().x <= (_object->getComponent<Transform>()->getPosition().x + _object->getComponent<Transform>()->getScale().x / 0.7f)
					&& getEntity()->getComponent<Transform>()->getPosition().x >= (_object->getComponent<Transform>()->getPosition().x - _object->getComponent<Transform>()->getScale().x / 0.7f))
				{
					if (getEntity()->getComponent<Transform>()->getPosition().y <= (_object->getComponent<Transform>()->getPosition().y + _object->getComponent<Transform>()->getScale().y / 0.7f)
						&& getEntity()->getComponent<Transform>()->getPosition().y >= (_object->getComponent<Transform>()->getPosition().y - _object->getComponent<Transform>()->getScale().y / 0.7f))
					{
						if (getEntity()->getComponent<Transform>()->getPosition().z <= (_object->getComponent<Transform>()->getPosition().z + _object->getComponent<Transform>()->getScale().z / 0.7f)
							&& getEntity()->getComponent<Transform>()->getPosition().z >= (_object->getComponent<Transform>()->getPosition().z - _object->getComponent<Transform>()->getScale().z / 0.7f))
						{
							getEntity()->getComponent<Transform>()->vel = -getEntity()->getComponent<Transform>()->vel;
							_object->setDestroy(true);

						}
					}
				}
			}
		}

	}
}