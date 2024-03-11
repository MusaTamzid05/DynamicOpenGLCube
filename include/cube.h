#ifndef CUBE_H
#define CUBE_H

#include "entity.h"
#include <vector>

struct Light;

struct CubeMesh {
    CubeMesh();
    virtual ~CubeMesh();

    void increase_triangle();
    void decrease_triangle();

    void update_active_vertices();
    int get_total_draw_points() const;


    std::vector<float> vertices;
    std::vector<float> active_vertices;

    int current_triangle_no;
    int vertex_length;
    int total_position_vertex_length; // number of floats that represents vertex position







};

struct Cube : Entity {
    Cube(Light* light);
    virtual ~Cube();

    void reset_mesh();
    void render();

    void increase_triangle();
    void decrease_triangle();

    unsigned int texture_id;
    CubeMesh mesh;

    int total_draw_points;

    Light* light;
};

#endif
