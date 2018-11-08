#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>

namespace Aspect
{
	namespace Engine
	{
		class VertexBuffer
		{
			GLuint id;
			int components;
			bool dirty;

		public:
			std::vector<GLfloat> data;
			VertexBuffer();
			void add(glm::vec3 value);
			void add(glm::vec4 value);
			void add(glm::vec2 value);
			int getComponents();
			int getDataSize();
			GLuint getId();

		};


	}

}
