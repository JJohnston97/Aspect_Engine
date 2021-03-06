#include <iostream> // Iostream for the use of cout for debug
#include <string>	// Include string for use of string
#include <vector>	// Include for the use of vector
#include <memory>	// Include for use of shared_ptr

#ifndef _ENTITY_H_	
#define _ENTITY_H_

#define ADDCOMPONENT \
  std::shared_ptr<T> rtn = std::make_shared<T>(); \
  rtn->entity = self; \
  rtn->m_begin = false; \
  components.push_back(rtn);


namespace Aspect	// Namespace 1
{
	namespace Engine // Namespace 2
	{
		class Program;		/// Initialise the program class  
		class Component;	/// Initialise the component class
		class Entity		/// Initialise the entity class
		{
		public:
			template <typename T>				/// Type T Template class to get a single component
			std::shared_ptr<T> getComponent()	// Function
			{
				for (size_t i = 0; i < components.size(); i++)	// Loop through the list of components
				{
					std::shared_ptr<T> tst = std::dynamic_pointer_cast<T>(components.at(i)); // For each cast a dynamic pointer

					if (tst)	// If it is equal to itself, hence the list has ran all the way through
					{
						return tst;	// Return
					}
				}

				throw std::exception(); // Any issues, throw an exception
			}

			template <typename T>				/// Type T Template class to get a single component
			bool hasComponent()	// Function
			{
				for (size_t i = 0; i < components.size(); i++)	// Loop through the list of components
				{
					std::shared_ptr<T> tst = std::dynamic_pointer_cast<T>(components.at(i)); // For each cast a dynamic pointer

					if (tst)	// If it is equal to itself, hence the list has ran all the way through
					{
						return true;	// Return
					}
				}

				return false;
			}

		
			template <typename T>				/// Type t template class to add a single component
			std::shared_ptr<T> addComponent()	// Function
			{
				ADDCOMPONENT			
					rtn->onInit();				// Add the single component depending on class type and return

				return rtn;
			}

			template <typename T, typename A>	/// Type t template class to add 2 components
			std::shared_ptr<T> addComponent(A a)
			{
				ADDCOMPONENT
					rtn->onInit(a);

				return rtn;
			}

			template <typename T, typename A, typename B>	/// Type t template class to add 3 components
			std::shared_ptr<T> addComponent(A a, B b)
			{
				ADDCOMPONENT
					rtn->onInit(a, b);

				return rtn;
			}

			
			void count();			/// Update function
			void display();			/// Draw function
			void setDestroy(bool destroy) { this->destroy = destroy; }; /// Destory game objects
			bool isDestroyed() { return destroy; }	// Used for turning mesh renderer off
			bool destroy;							// Bool for destoryed or not
			std::vector<std::shared_ptr<Component> > components; // Vector list of components to store all the components of the entity
			std::shared_ptr<Program> getProgram();				/// Get program function
			std::weak_ptr<Program> program;						// Weak pointer to program
			std::weak_ptr<Entity> self;
		};
	}
}

#endif // _ENTITY_H_