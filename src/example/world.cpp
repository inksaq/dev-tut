#include "world.h"
#include "core/graphics/shape.h"
#include <cstddef>
#include <cstdio>

namespace scenes{
    WorldScene::WorldScene(core::graphics::Window& window): 
        Scene(window),

        view3d(180.0f,16.9f,0.1f,100.0f)
        

    {

    }

    void WorldScene::init(){

        core::Vector2u window_size = m_window.get_size();

        float fov = glm::radians(45.0f); // converting 45 degrees to radians
        float aspectRatio = static_cast<float>(window_size.y) / static_cast<float>(window_size.x);
        view3d.create(fov, aspectRatio, 0.1f, 100.0f);
     
    
        //map_generator.m_sprite.m_rotation = glm::quat(core::Vector3f(glm::radians(180.0f),0,0));
        view3d.m_position = core::Vector3f(500,-180,0);
        //sprite.setup_shaders();
        /*
        core::ShapeData rect = core::shapedata::Rectangle();
        rect.bind();
        sprite.set_shapedata(rect);
        */
        // invert Z axis so the view point towards positive Z axis
        view3d.m_scale = core::Vector3f(1.8,1.8, -1.0);
    }

void WorldScene::createAndUseShaders() {
    // Paths to shader files
    std::string vertexShaderPath = "./data/shader/vertex.vert";
    std::string fragmentShaderPath = "./data/shader/fragment.frag";

    // Create vertex shader
    core::gl::Shader vertexShader;
    vertexShader.create(vertexShaderPath, GL_VERTEX_SHADER);
    std::printf("vertex loaded");
    if (!vertexShader.compile()) {
        std::cerr << "Vertex shader compilation failed." << std::endl;
        return;
    }

    // Create fragment shader
    core::gl::Shader fragmentShader;
    fragmentShader.create(fragmentShaderPath, GL_FRAGMENT_SHADER);
    if (!fragmentShader.compile()) {
        std::cerr << "Fragment shader compilation failed." << std::endl;
        return;
    }

    // Create shader program
    core::gl::ShaderProgram shaderProgram;
    shaderProgram.attach(vertexShader);
    shaderProgram.attach(fragmentShader);

    if (!shaderProgram.link()) {
        std::cerr << "Shader program linking failed." << std::endl;
        return;
    }

    float vertices[] = {
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
    };

// Create and bind a vertex array
    core::gl::VertexArray VAO;
    VAO.bind();

// Create and bind a vertex buffer
    core::gl::VertexBuffer VBO;
    VBO.bind();
    VBO.set_data(vertices, sizeof(vertices), GL_STATIC_DRAW);

// Define vertex attribute layout
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

// Unbind the VAO and VBO
    VBO.unbind();
    VAO.unbind();

    // Use the shader program
    shaderProgram.use();
    


// Calculate rotation
float angle = glfwGetTime(); // Or your own time variable
glm::mat4 model = glm::rotate(glm::mat4(1.0f), angle, glm::vec3(0.0f, 0.0f, 1.0f));

// Set model matrix in shader
unsigned int modelLoc = glGetUniformLocation(shaderProgram.get_id(), "model");
glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));

// Bind vertex array and draw
VAO.bind();
glDrawArrays(GL_TRIANGLES, 0, 3);

// Unbind VAO
VAO.unbind(); 
    // ... Now you can do rendering with this shader program

    // Cleanup: Detach and delete shaders if they are no longer needed
    shaderProgram.detach(vertexShader);
    shaderProgram.detach(fragmentShader);
}
    



    void WorldScene::handle_event(core::Event event){

        if (event.type == GLEQ_WINDOW_RESIZED){
           float fov = glm::radians(45.0f); // converting 45 degrees to radians
        float aspectRatio = static_cast<float>(event.size.width) / static_cast<float>(event.size.height);
        view3d.create(fov, aspectRatio,0.1f, 100.0f); 
        }
    }

    void WorldScene::update(float delta){
    }




    void WorldScene::draw(core::graphics::Window& window){

        window.clear(core::graphics::Color(0,12,0,255));    

        
        //sprite.draw();

        view3d.set_active();
    }
}
