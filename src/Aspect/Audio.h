#include <GL/glew.h>	// Include Glew for use of openGL
#include <glm/glm.hpp>	// Include GLM

#include <vector>		// Include vector for the use of vectors
#include <string>		// Include string for the use of string in audio samples
#include <memory>		// Include memory for the use of shared_ptr

namespace Aspect
{
	namespace Engine
	{

		struct SoundClip;
	
		class Audio
		{
			std::shared_ptr<SoundClip> Sclip;
		
		public:
			Audio();
			Audio(std::string path);
			void load(std::string path);
			void play(float vol, float varMin, float varMax);
			void play();



		};
	
	
	
	}
}
	
