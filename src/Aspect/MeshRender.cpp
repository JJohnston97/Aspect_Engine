#include "VertexBuffer.h"
#include "VertexArray.h"
#include "MeshRender.h"
#include "Program.h"
#include "Material.h"
#include "ShaderProgram.h"
#include <glm/ext.hpp>

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
			shader->setUniform("in_Model", glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -10)));
			//shader->setUniform("in_Projection", glm::mat4(1.0f));

			shader->setUniform("in_Projection", glm::perspective(glm::radians(45.0f),
				(float)1080/ (float)900, 0.1f, 100.f));

			shader->setUniform("in_View", glm::mat4(1.0));
			
			shader->setUniform("in_Material", mat);

			shader->draw(shape);
		}
	}

	
}
