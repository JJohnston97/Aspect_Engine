#include <GL/glew.h>	// Include glew
#include <glm/glm.hpp>	// Include glm
#include <string>		// Allows for the use of string

#ifndef _MATERIAL_H_
#define _MATERIAL_H_

namespace Aspect	// Namespace 1
{
	namespace Engine // Namespace 2
	{
		class Material	///  Class material used for textures
		{
			GLuint id;  
			glm::vec2 size; // Glm for size of material

		public:
			Material(std::string path); /// Material takes in a string, the name of the texture file
			glm::vec2 getSize();		/// Get size function to return the size of texture
			GLuint getId();				/// Get ID to get texture ID

			int w; // int width
			int h; // int height
			int channels; // int for channel its contained in


		};
	}
}

#endif // !_MATERIAL_H_