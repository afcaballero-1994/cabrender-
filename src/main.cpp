#include <glad/gl.h>
#include <GLFW/glfw3.h>
#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/string_cast.hpp>
#include <glm/ext/matrix_clip_space.hpp>
#include "Shader.hpp"
#include "Camera.hpp"

#include "Display.hpp"
#include "Texture.hpp"
#include "Object.hpp"
#include <vector>

Camera camera;

void printDisplayProperties(){
    const GLubyte *renderer = glGetString( GL_RENDERER );
    const GLubyte *vendor = glGetString( GL_VENDOR );
    const GLubyte *version = glGetString( GL_VERSION );
    const GLubyte *glslVersion = glGetString( GL_SHADING_LANGUAGE_VERSION );
    GLint major, minor;
    glGetIntegerv(GL_MAJOR_VERSION, &major);
    glGetIntegerv(GL_MINOR_VERSION, &minor);
    printf("GL Vendor : %s\n", vendor);
    printf("GL Renderer : %s\n", renderer);
    printf("GL Version (string) : %s\n", version);
    printf("GL Version (integer) : %d.%d\n", major, minor);
    printf("GLSL Version : %s\n", glslVersion);
}

int main() {
    constexpr int w = 16 * 80;
    constexpr int h = 9 * 80;
    Display display(w, h, "Renderer");

    Shader shader("../resources/shader.vs", "../resources/shader.fs");
    //printDisplayProperties();
    glm::vec3 p1 {0.5f, -0.5f, 0.0f};
    glm::vec3 p2 {-0.5f, -0.5f, 0.0f};
    glm::vec3 p3 {0.0f, 0.5f, 0.0f};
    glm::vec2 c1 {0.0f, 0.0f};
    glm::vec2 c2 {0.5f, 1.0f};
    glm::vec2 c3 {1.0f, 0.0f};

    Vertex v1{&p1, &c1};
    Vertex v2{&p2, &c2};
    Vertex v3{&p3, &c3};

    std::vector<Vertex> vertices {
        v1, v2, v3
            // positions         // colors
//            glm::vec3 (0.5f, -0.5f, 0.0f),   // bottom right
//            glm::vec3 (-0.5f, -0.5f, 0.0f),  // bottom left
//            glm::vec3 (0.0f,  0.5f, 0.0f),  // top

    };
    Mesh mesh(&vertices);

    glUseProgram(shader.ID);
    //prjectiion 2
    //view 3

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, glm::vec3(0.1f, 0.1f, 0.1f) );
    glUniformMatrix4fv(3, 1, GL_FALSE, &model[0][0]);

    glm::mat4 projection = glm::mat4(1.0f);
    projection = glm::perspective(glm::radians(45.0f), (float)w / (float)h, 0.1f, 100.0f);
    glUniformMatrix4fv(4, 1, GL_FALSE, &projection[0][0]);

    camera.position = glm::vec3(0.2f, 0.0f, 3.0f);
    glm::mat4 view = camera.getViewMatrix();
    glUniformMatrix4fv(5, 1, GL_FALSE, &view[0][0]);



    //texture
    Texture texture("../resources/wall.jpg");


    glBindVertexArray(mesh.VAO);
    while(!glfwWindowShouldClose(display.window)){
        glfwPollEvents();
        glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glDrawArrays(GL_TRIANGLES, 0, 3);
        glfwSwapBuffers(display.window);
    }
    glfwTerminate();

    return 0;
}
