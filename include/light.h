#ifndef LIGHT_H
#define LIGHT_H

#include "entity.h"

struct Light : Entity {
    Light(const glm::vec3& position, float speed=5.0f);
    virtual ~Light();

    void update_position(const glm::vec3& offset, float delta_time);

    void render();
    void update();

    float m_speed;






};

#endif
