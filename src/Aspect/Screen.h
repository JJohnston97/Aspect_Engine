/*#ifndef ASPECT_ENGINE_SCREEN_H
#define ASPECT_ENGINE_SCREEN_H

namespace aspect			// Namespace of the engine
{

	namespace engine		// Namespcae of the engine
	{

		class Program;		// Create program class
		
		class Screen		// Create screen class
		{
			friend class Program;  // Friend class to be able to access private members of the class

		public:
			static int getWidth(); // Get width of screen (static as only 1)
			static int getHeight();// Get height of screen
			static void setScreenResolution(int width, int height); // Set the screen res

		private:
			static int width;
			static int height;
		
		};
	}

}

#endif*/
