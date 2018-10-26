#include "Material.h"

#include <stb_image/stb_image.h>

namespace Aspect
{
	namespace Engine
	{
		Material::Material(std::string path)
		{
			w = 0;
			h = 0;
			channels = 0;

			unsigned char *data = stbi_load(path.c_str(), &w, &h, &channels, 4);

			if (!data)
			{
				throw std::exception();
			}
			
			size.x = w;
			size.y = h;

			glGenTextures(1, &id);

			if (!id)
			{
				throw std::exception();
			}

			glBindTexture(GL_TEXTURE_2D, id);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			free(data);
			glGenerateMipmap(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, 0);
		
		}

		glm::vec2 Material::getSize()
		{
			return size;
		}

		GLuint Material::getId()
		{
			return id;
		}

	}
}