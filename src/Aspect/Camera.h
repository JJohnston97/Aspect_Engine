#include <vector> // Include vector for use of vectors
#include <memory> // Include memeory for use of shared_ptr

#include "Component.h" // Include Component header

#ifndef _CAMERA_H_
#define _CAMERA_H_

namespace Aspect	// Use of part 1 aspect namespace
{
	namespace Engine // Use of second part engine namespace
	{
		class Camera : public Component /// Camera class inherits from component as camera is a component
		{
		public:
			
			void onInit(); /// Init for camera class

			glm::mat4 getProjectionMatrix(); /// Projecttion matrix used within the mesh render for the camera draw
											 // Returns inverse view matrix

		};

	}

}

#endif // _CAMERA_h_