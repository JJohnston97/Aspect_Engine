#include <GL/glew.h>
#include <glm/glm.hpp>

#include <vector>
#include <string>
#include <memory>

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
	
