#include <GL/glew.h>    // Include Glew
#include <glm/glm.hpp>  // Include GLM
#include "Component.h"	// Include component

#include <vector>		// Include vector for the use of vectors

#ifndef _MESHRENDER_H_
#define _MESHRENDER_H_

namespace Aspect	// Namespace 1
{
	namespace Engine // Namespace 2
	{
		class VertexArray;   /// Initialise Vertex Array class
		class Material;		 /// Initialise Material Class
		class ShaderProgram; /// Initialise Shader Program

		class MeshRender : public Component  /// MeshRender is an inherited class of component
		{
		public:
			void onInit();   /// On init component function
			std::shared_ptr<Entity> camera;  // List of cameras
			bool MrEnable = true;			 // Mesh renderer enable / disable
			void Cube();					 /// Draw cube object
			void Triangle();				 /// Draw Triangle
			void Mesh(const std::string& _mesh); /// Draw a mesh of any obj
			void setTexture(const std::string& _texture); /// Set the texture of that model

		private:
			void onDisplay();  /// On display works similar to draw function
			void onCount();	   /// On count is update

			std::shared_ptr<VertexArray> shape;    // shape object
			std::shared_ptr<ShaderProgram> shader; // shader object
			std::shared_ptr<Material> mat;         // Material object

		};

	}

}


#endif // _MESHRENDER_H_
