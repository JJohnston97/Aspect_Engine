#include <GL/glew.h>	// Include glew
#include <glm/glm.hpp>	// Include glm
#include <vector>		// Allows for the use of vector
#include <string>		// Allows for the use of string

#ifndef _SHADERPROGRAM_H_
#define _SHADERPROGRAM_H_

namespace Aspect  // Namespace 1
{
	namespace Engine // Namespace 2
	{
	
	class VertexArray; /// Initialise Vertex array class
	class Material;	   /// Initialise Material class 

	struct Sampler /// Struct for the material sample
	{
		GLint id;	// Material ID
		std::shared_ptr<Material> mat; // material object for the mesh renderer
	};

	class ShaderProgram /// Shader Program class used for sending info to the shader
	{
		GLuint id;
		std::vector<Sampler> samplers; // List of samples

	public:
		ShaderProgram(std::string vert, std::string frag);	/// Shader program function that sends the info through the shaders
		void draw(std::shared_ptr<VertexArray> vArray);		/// Draws the object to the screen
		void setUniform(std::string uniform, glm::vec4 value); /// Set uniform will asign the uniform ID to the texture
		void setUniform(std::string uniform, float value); /// Set uniform will asign the uniform ID to the texture
		void setUniform(std::string uniform, glm::mat4 value); /// Set uniform will asign the uniform ID to the texture
		void setUniform(std::string uniform, std::shared_ptr<Material> mat); /// Allows the use of texture
		GLuint getId(); /// Gets the id from the object

	};

	}
}

#endif // _SHADERPROGRAM_H_





