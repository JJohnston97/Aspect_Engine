#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Component.h"


#include <vector>

namespace Aspect
{
	namespace Engine
	{
		class VertexArray;
		class Material;
		class ShaderProgram;

		class MeshRender : public Component
		{
		public:
			void onInit();
			std::shared_ptr<Entity> camera;

		private:
			void onDisplay();
			void onCount();

			std::shared_ptr<VertexArray> shape;
			std::shared_ptr<ShaderProgram> shader;
			std::shared_ptr<Material> mat;

		};

	}

}
