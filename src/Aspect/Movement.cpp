/// @Movement.cpp
/// @Controls my enemy movement in game

// System Includes
#include <iostream>
#include <memory>
#include <windows.h>
#include <GL/glew.h>

#define GLM_FORCE_CTOR_INIT
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <SDL.h>

// Project Include
#include "Movement.h"
#include "Transform.h"
#include "Entity.h"

namespace Aspect
{
	namespace Engine
	{
		class Movement; // Initilise Movement class

		Movement::Movement() // Constructor 
		{


		}

		void Movement::onCount() // Update function called every frame
		{
			// Moves the enemy objects depending on the transform position 
				if (getEntity()->getComponent<Transform>()->getPosition().y <= -7.0f || getEntity()->getComponent<Transform>()->getPosition().y >= 7.0f)
				{
					getEntity()->getComponent<Transform>()->vel = -getEntity()->getComponent<Transform>()->vel;
				}

				getEntity()->getComponent<Transform>()->Translate(0.0f, getEntity()->getComponent<Transform>()->vel, 0.0f);


		}


	}


}