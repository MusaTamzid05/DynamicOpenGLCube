#include "light.h"
#include "headers.h"
#include "shader.h"
#include "camera.h"

Light::Light(const glm::vec3& position, float speed) {
    this->position = position;
    m_speed =  speed;

    m_shader = new Shader("../shaders/light.vs", "../shaders/light.fs");

    std::vector<float> vertices = {

        // front
       
        // triangle = 1
        -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, // bottom left
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // top right
        -1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // top left


        // triangle = 2
        1.0f, -1.0f, 1.0f, 1.0f, 0.0f, // bottom right
        1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // top right
        -1.0f, -1.0f, 1.0f, 0.0f, 0.0f, // bottom left

        // back
       
        // triangle = 3
        -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, // bottom left
        1.0f, 1.0f, -1.0f, 0.0f, 1.0f, // top right
        -1.0f, 1.0f, -1.0f, 1.0f, 1.0f, // top left


        // triangle = 4
        1.0f, -1.0f, -1.0f, 0.0f, 0.0f, // bottom right
        1.0f, 1.0f, -1.0f, 0.0f, 1.0f, // top right
        -1.0f, -1.0f, -1.0f, 1.0f, 0.0f, // bottom left

        // left
        // triangle 5
        
        -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, // bottom left
        -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // top right
        -1.0f, 1.0f, -1.0f, 0.0f, 1.0f, // top left

        // triangle 6
        -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, // bottom right
        -1.0f, 1.0f, 1.0f, 1.0f, 1.0f, // top right
        -1.0f, -1.0f, -1.0f, 0.0f, 0.0f, // bottom left


        // right
        // triangle 7
        
        1.0f, -1.0f, -1.0f, 1.0f, 0.0f, // bottom left
        1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // top right
        1.0f, 1.0f, -1.0f, 1.0f, 1.0f, // top left

        // triangle 8
        1.0f, -1.0f, 1.0f, 0.0f, 0.0f, // bottom right
        1.0f, 1.0f, 1.0f, 0.0f, 1.0f, // top right
        1.0f, -1.0f, -1.0f, 1.0f, 0.0f, // bottom left

        // top


        // triangle 9
        -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom left
        1.0f, 1.0f, -1.0f, 1.0f, 1.0f, // top right
        -1.0f, 1.0f, -1.0f, 0.0f, 1.0f, // top left

        // triangle 10
        1.0f, 1.0f, 1.0f, 1.0f, 0.0f, // bottom right
        1.0f, 1.0f, -1.0f, 1.0f, 1.0f, // top right
        -1.0f, 1.0f, 1.0f, 0.0f, 0.0f, // bottom left


        // bottom


        // triangle 11
        -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, // bottom left
        1.0f, -1.0f, -1.0f, 0.0f, 1.0f, // top right
        -1.0f, -1.0f, -1.0f, 1.0f, 1.0f, // top left

        // triangle 12
        1.0f, -1.0f, 1.0f, 0.0f, 0.0f, // bottom right
        1.0f, -1.0f, -1.0f, 0.0f, 1.0f, // top right
        -1.0f, -1.0f, 1.0f, 1.0f, 0.0f, // bottom left


    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER,vertices.size() *  sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);


    m_shader->use();
    glm::mat4 projection = Camera::get_instance()->get_projection();
    m_shader->set_mat4("projection", projection);


}

Light::~Light() {

}

void Light::render() {
    Entity::render();


    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0 ,36);

}


void Light::update() {

}


void Light::update_position(const glm::vec3& offset, float delta_time) {
    position += (offset * m_speed * delta_time);

}




