#include <GL/glew.h>   // Include glew
#include <glm/glm.hpp> // Include glm

#include <vector>		// Allows the use of vector

#ifndef _VERTEXBUFFER_H_
#define _VERTEXBUFFER_H_

namespace Aspect // Namespace 1
{
	namespace Engine // Namespace 2
	{
		class VertexBuffer /// Vertex Buffer class used to create single vertex
		{
			GLuint id;		// ID
			int components; // Number of Components 
			bool dirty;		// Bool dirty

		public:
			std::vector<GLfloat> data;	// vector of data
			VertexBuffer();				/// Vertex Buffer constructor
			void add(glm::vec3 value);	/// Add data 
			void add(glm::vec4 value);
			void add(glm::vec2 value);
			int getComponents();		/// Gets the components on an entity
			int getDataSize();			/// Get the size of data in the buffer
			GLuint getId();				/// Get the id

		};


	}

}
#endif // !_VERTEXBUFFER_H
