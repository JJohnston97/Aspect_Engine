#include "VertexBuffer.h"
#include "VertexArray.h"
#include "MeshRender.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "Program.h"
#include "Material.h"
#include "Entity.h"
#include "Transform.h"
#include "ShaderProgram.h"
#include "Camera.h"

// glm max...

namespace Aspect
{
	namespace Engine
	{
		void MeshRender::onInit()
		{
			shader = std::make_shared<ShaderProgram>("../Shaders/vert.txt", "../Shaders/frag.txt");

			shape = std::make_shared<VertexArray>("../Objs/Box.obj");
			mat = std::make_shared<Material>("../Images/something.png");
		}

		void MeshRender::onCount()
		{
			// if (input->getKey("LEFT"))
			//{
			//  position.x ++;
			//}
		}

		void MeshRender::onDisplay()
		{
			shader->setUniform("in_Model", getEntity()->getComponent<Transform>()->getModelMatrix());
				//getEntity()->getComponent<Transform>()->getModelMatrix());
				
				//glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -10))); 
			shader->setUniform("in_Projection", glm::mat4(1.0f));

			shader->setUniform("in_Projection", getProgram()->getCurrentCamera()->getProjectionMatrix());  //->getComponent<Camera>()->getProjectionMatrix());

			shader->setUniform("in_View", camera->getComponent<Transform>()->getViewMatrix());
				//glm::mat4(1.0));
		
			shader->setUniform("in_Material", mat);

			shader->draw(shape);
		}
	}

	
}
