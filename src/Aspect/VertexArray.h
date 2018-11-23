#include <GL/glew.h>	// Include glew 
#include <glm/glm.hpp>	// Include glm
#include <vector>		// Allow for the use of vectors 
#include <string>		// Allow for the use of string
#include <memory>	    // Allow for the use of shared_ptr

#ifndef _VERTEXARRAY_H_
#define _VERTEXARRAY_H_


namespace Aspect	// Namespace 1
{
	namespace Engine // Namespace 2
	{
		class VertexBuffer; /// Initialise the vertex buffer object

		class VertexArray	/// Vertex Array class, used to load in objs
		{
			GLuint id;				// ID
			bool dirty;				// used for lock
			std::vector<VertexBuffer *> buffers;  // Raw pointer to buffers

			void splitStringWhitespace(std::string& input, std::vector<std::string>& output);   /// Function used to read in files for the object loader
			void splitString(std::string& input, char splitter, std::vector<std::string>& output);	/// Function used to read information for object loader 

		public:
			VertexArray();					/// Constructor for vertex array
			VertexArray(std::string path);	/// Vert cont taking a string
			void setBuffer(std::string attribute, VertexBuffer *buffer); /// Function to set the buffer object
			int getVertexCount();		/// Get the vertex count of a model
			GLuint getId();		/// Get the id of the object

		};
	}
}
#endif // !_VERTEXARRAY_H_
	
