#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>
#include <memory>

namespace Aspect
{
	namespace Engine
	{

		class VertexBuffer;

		class VertexArray
		{
			GLuint id;
			bool dirty;
			std::vector<std::shared_ptr<VertexBuffer> > buffers;

		public:
			VertexArray();
			void setBuffer(std::string attribute, std::weak_ptr<VertexBuffer> buffer);
			int getVertexCount();
			GLuint getId();

		};

	}
}
	
