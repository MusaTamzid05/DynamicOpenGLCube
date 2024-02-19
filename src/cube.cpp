#include "cube.h"
#include "shader.h"
#include "headers.h"
#include "camera.h"
#include "utils.h"
#include <iostream>

CubeMesh::CubeMesh():
    current_triangle_no(4), 
    vertex_length(5),
    total_position_vertex_length(3)
{

    // bottom left
    //  top right
    //  top left
    vertices = {

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

    };



}

CubeMesh::~CubeMesh() {

}

void CubeMesh::increase_triangle() {

}
void CubeMesh::decrease_triangle() {

}

void CubeMesh::update_active_vertices() {
    int total_values = current_triangle_no * vertex_length * total_position_vertex_length;
    active_vertices.clear();

    for(int i = 0; i < total_values; i += 1) 
        active_vertices.push_back(vertices[i]);

}


int CubeMesh::get_total_draw_points() const {
    return current_triangle_no * total_position_vertex_length;
}

Cube::Cube() {

    m_shader = new Shader("../shaders/cube.vs", "../shaders/cube.fs");

    mesh.update_active_vertices();
    std::vector<float> vertices =  mesh.active_vertices;
    std::cout << vertices.size() << "\n";
    total_draw_points = mesh.get_total_draw_points();
    std::cout << total_draw_points  << "\n";

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER,vertices.size() *  sizeof(float), vertices.data(), GL_STATIC_DRAW);

    // position attribute
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    // texture coord attribute
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindVertexArray(0);

    m_shader->use();
    glm::mat4 projection = Camera::get_instance()->get_projection();
    m_shader->set_mat4("projection", projection);

    texture_id = load_texture("../resources/number.png");


}

Cube::~Cube() {

}



void Cube::render() {

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, texture_id);

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0 , total_draw_points);


}
