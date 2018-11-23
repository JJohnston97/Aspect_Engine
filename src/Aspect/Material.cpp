/// @Material.cpp
/// @Handles textures for game objects


// Project Includes
#include "Material.h"


// System inlcudes
#include <stb_image/stb_image.h>

namespace Aspect
{
	namespace Engine
	{
		Material::Material(std::string path) // Material function that takes a string of file name
		{
			w = 0;	// Width
			h = 0;	// Height
			channels = 0;	// Channels

			unsigned char *data = stbi_load(path.c_str(), &w, &h, &channels, 4);

			// If there is no data, throw an exception
			if (!data)
			{
				throw std::exception();
			}
			
			size.x = w;	// X value is equal to width
			size.y = h; // Y value is equal to height

			glGenTextures(1, &id);

			// If it has no ID, throw and exception
			if (!id)
			{
				throw std::exception();
			}

			// Bind the texture
			glBindTexture(GL_TEXTURE_2D, id);

			// Create the texture
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
			free(data);
			glGenerateMipmap(GL_TEXTURE_2D);

			glBindTexture(GL_TEXTURE_2D, 0);
		
		}

		// Get the size of the material
		glm::vec2 Material::getSize()
		{
			return size;
		}

		// Gte material ID
		GLuint Material::getId()
		{
			return id;
		}

	}
}