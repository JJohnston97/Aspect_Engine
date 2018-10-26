#include <GL/glew.h>
#include <glm/glm.hpp>

#include <string>

#ifndef _MATERIAL_H_
#define _MATERIAL_H_



namespace Aspect
{
	namespace Engine
	{
		class Material
		{
			GLuint id;
			glm::vec2 size;

		public:
			Material(std::string path);
			glm::vec2 getSize();
			GLuint getId();

			int w;
			int h;
			int channels;


		};
	}
}

#endif // !_MATERIAL_H_