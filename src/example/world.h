#include "core/graphics/sprite.h"
#include "core/system/scene.h"
#include "core/graphics/graphics.h"

namespace scenes{

class WorldScene : public core::Scene{
        public:

        // objects
        core::graphics::View3D view3d;
        //core::graphics::Sprite sprite;

        int draw_mode = 0;

 

        WorldScene(core::graphics::Window& window);
        void createAndUseShaders();
        void init();
        void handle_event(core::Event event);
        void update(float delta);
        void draw(core::graphics::Window& window);
    };
}
