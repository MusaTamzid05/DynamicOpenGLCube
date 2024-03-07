#ifndef ENTITY_H
#define ENTITY_H

struct Shader;

#include <glm/glm.hpp>


struct Entity {
    Entity();
    virtual ~Entity();

    virtual void render() = 0;
    virtual void update();

    Shader* m_shader;

    unsigned int VAO;
    unsigned int VBO;
    unsigned int EBO;

    glm::vec3 position;


};
#endif

