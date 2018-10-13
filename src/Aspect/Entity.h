#include <iostream>
#include <string>
#include <vector>
#include <memory>

#ifndef _ENTITY_H_
#define _ENTITY_H_

#define ADDCOMPONENT \
  std::shared_ptr<T> rtn = std::make_shared<T>(); \
  rtn->entity = self; \
  rtn->began = false; \
  components.push_back(rtn);


namespace Aspect
{
	namespace Engine
	{
		class Program;
		class Component;
		class Entity
		{
		public:
			template <typename T>
			std::shared_ptr<T> getComponent()
			{
				for (size_t i = 0; i < components.size(); i++)
				{
					std::shared_ptr<T> tst = std::dynamic_pointer_cast<T>(components.at(i));

					if (tst)
					{
						return tst;
					}
				}

				throw std::exception();
			}

			template <typename T>
			std::shared_ptr<T> addComponent()
			{
				ADDCOMPONENT
					rtn->onInit();

				return rtn;
			}

			template <typename T, typename A>
			std::shared_ptr<T> addComponent(A a)
			{
				ADDCOMPONENT
					rtn->onInit(a);

				return rtn;
			}

			template <typename T, typename A, typename B>
			std::shared_ptr<T> addComponent(A a, B b)
			{
				ADDCOMPONENT
					rtn->onInit(a, b);

				return rtn;
			}

			
			void count();
			void display();
			std::vector<std::shared_ptr<Component> > components;
			std::shared_ptr<Program> getProgram();
			std::weak_ptr<Program> program;


			// Trying to push it
		};
	}
}

#endif // _ENTITY_H_