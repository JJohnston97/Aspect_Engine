#include <iostream>
#include <memory>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <SDL.h>


#include "BoxCollider.h"

namespace Aspect
{
	namespace Engine
	{
		class BoxCollider;

		void BoxCollider::BoxCollision(std::shared_ptr<Entity> _object)
		{
			
			


			/*if (e->GetPosition().x <= (_object->getPosition().x + _object->getScale().x / 1)		//If the player x position greater than or equal to the object x position + a whole of the object
				&& e->GetPosition().x >= (_object->getPosition().x) - _object->getScale().x / 1)		//Bounding Box collsiion
			{
				if (e->GetPosition().y <= (_object->getPosition().y + _object->getScale().y / 1)			//Using Y and Z because my objects are in space and could be hit from any position
					&& e->GetPosition().y >= (_object->getPosition().y - _object->getScale().y / 1))
				{
					if (e->GetPosition().z <= (_object->getPosition().z + _object->getScale().z / 1)
						&& e->GetPosition().z >= (_object->getPosition().z - _object->getScale().z / 1))	//Add a whole of the scale and minus a whole of the scale for bounding box
					{
						std::cout<<"hit"<<std::endl;
					}
				}
			}*/
		}
		
	}
}