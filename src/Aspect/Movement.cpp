#include <iostream>
#include <memory>
#include <windows.h>
#include <GL/glew.h>

#define GLM_FORCE_CTOR_INIT
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <SDL.h>

#include "Movement.h"
#include "Transform.h"
#include "Entity.h"

namespace Aspect
{
	namespace Engine
	{
		class Movement;
		


		Movement::Movement()
		{


		}

		void Movement::onCount()
		{
	
				if (getEntity()->getComponent<Transform>()->getPosition().y <= -7.0f || getEntity()->getComponent<Transform>()->getPosition().y >= 7.0f)
				{
					getEntity()->getComponent<Transform>()->vel = -getEntity()->getComponent<Transform>()->vel;
				}

				getEntity()->getComponent<Transform>()->Translate(0.0f, getEntity()->getComponent<Transform>()->vel, 0.0f);


		}


	}


}