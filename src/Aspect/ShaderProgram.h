#include <GL/glew.h>
#include <glm/glm.hpp>
#include <vector>

#include <string>

namespace Aspect
{
	namespace Engine
	{


	class VertexArray;
	class Material;

	struct Sampler
	{
		GLint id;
		std::shared_ptr<Material> mat;
	};

	class ShaderProgram
	{
		GLuint id;
		std::vector<Sampler> samplers;

	public:
		ShaderProgram(std::string vert, std::string frag);
		void draw(std::shared_ptr<VertexArray> vArray);
		void setUniform(std::string uniform, glm::vec4 value);
		void setUniform(std::string uniform, float value);
		void setUniform(std::string uniform, glm::mat4 value);
		void setUniform(std::string uniform, std::shared_ptr<Material> mat);
		GLuint getId();

	};

	
	}

}







