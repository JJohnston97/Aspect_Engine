#include <iostream>
#include <Windows.h>
#include <memory>

#define shared std::shared_ptr
#define weak std::weak_ptr

int main()
{
	
	// Initialize engine
	shared<Core> core = Core::initialize();

	// Create a single in-game Object
	shared<Entity> entity = core->addEntity();

	// Add a very simple component to it
	weak<TestScreen> testScreen = entity->addComponent<TestScreen>();

	// Start the engine's main loop
	core->Start();

	
	return 0;

}