#ifndef LIGHT_H
#define LIGHT_H

#include "entity.h"

struct Light : Entity {
    Light(const glm::vec3& position);
    virtual ~Light();

    void render();
    void update();




};

#endif
