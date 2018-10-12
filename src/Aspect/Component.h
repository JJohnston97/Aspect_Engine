#include <iostream>
#include <string>
#include <vector>
#include <memory>

namespace Aspect
{
	namespace Engine
	{
		class Entity;
		class Program;

		class Component
		{
			friend class Entity;

		public:
			virtual ~Component();
			std::shared_ptr<Program> getProgram();
			std::shared_ptr<Entity> getEntity();

		private:
			std::weak_ptr<Entity> entity;
			bool began;

			virtual void onInit();
			virtual void onBegin();
			virtual void onCount();
			virtual void onDisplay();


			void addEntity();
			void count();



			// Trying to push it
		};
	}
}