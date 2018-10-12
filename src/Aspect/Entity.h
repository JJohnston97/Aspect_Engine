#include <iostream>
#include <string>
#include <vector>
#include <memory>


namespace Aspect
{
	namespace Engine
	{
		class Program;
		class Component;
		class Entity
		{
		public:

			Entity();
			~Entity();


			void addEntity();
			void count();
			void display();
			std::vector<std::shared_ptr<Component> > components;
			std::shared_ptr<Program> getProgram();
			std::weak_ptr<Program> program;


			// Trying to push it
		};
	}
}