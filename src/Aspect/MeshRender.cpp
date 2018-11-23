/// @MeshRender.cpp
/// @Mesh renderer component that allows the object to be drawn and passed through the graphics pipeline

// Project Includes
#include <glm/glm.hpp>
#include <glm/ext.hpp>

// System Includes 
#include "VertexBuffer.h"
#include "MeshRender.h"
#include "VertexArray.h"
#include "Program.h"
#include "Material.h"
#include "Entity.h"
#include "Transform.h"
#include "ShaderProgram.h"
#include "Camera.h"


namespace Aspect
{
	namespace Engine
	{
		
		void MeshRender::onInit()	// On it when the mesh renderer is used (Constructor)
		{
			shader = std::make_shared<ShaderProgram>("../Shaders/vert.txt", "../Shaders/frag.txt"); // Tell the program what shader to use

			shape = std::make_shared<VertexArray>("../Objs/Box.obj");	// Default game object if nothing is given (Box)

			mat = std::make_shared<Material>("../Images/Default.png");	// Default game texture if nothing is given (Black/white check)
		}

		void MeshRender::onCount()	// Update Function
		{

		}

		void MeshRender::onDisplay() // Draw Function
		{
			if (MrEnable == true)	// If the mesh renderer is enables
			{
				shader->setUniform("in_Model", getEntity()->getComponent<Transform>()->getModelMatrix());	// select the current model, get its transform, take that model matrix
				
				shader->setUniform("in_Projection", glm::mat4(1.0f));	// Projection matrix

				shader->setUniform("in_Projection", getProgram()->getCurrentCamera()->getProjectionMatrix());  // Get the program, get that current camera, draw the projection matrix from that projection

				shader->setUniform("in_View", getProgram()->getCurrentCamera()->getEntity()->getComponent<Transform>()->getViewMatrix()); // Get the program, get that current camera, draw the 
																																		  // projection matrix from that projection
				
				shader->setUniform("in_Material", mat); // Tell the mesh renderer what texture to use

				shader->draw(shape); // Draw the shape
			
			}
		}
		void MeshRender::Cube()  // If the object is a cube
		{
			shape = std::make_shared<VertexArray>("../Objs/Box.obj");	// Set the shape to me a cube
		}

		void MeshRender::Triangle() // If the object is a triangle
		{
			shape = std::make_shared <VertexArray>("../Objs/Triangle.obj"); // Draw a triangle
		}

		void MeshRender::Mesh(const std::string& _mesh) // If you want to draw a custome mesh
		{
			shape = std::make_shared<VertexArray>(_mesh); // Set the shape to draw a mesh
		}

		void MeshRender::setTexture(const std::string& _texture) // Allow for multi textures
		{
			mat = std::make_shared<Material>(_texture); // Set the material to be the passed in string
		}
	}

	
}
