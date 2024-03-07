#ifndef COMMAND_STATE_H
#define COMMAND_STATE_H

#include <SFML/Graphics.hpp>


struct Cube;
struct Light;

struct CommandState {
    virtual void handle(const sf::Event& event, float delta_time) = 0;
};

struct CameraCommandState : CommandState {
    CameraCommandState();
    virtual ~CameraCommandState();
    void handle(const sf::Event& event, float delta_time);

    bool first_mouse_move;
    float last_mouse_x;
    float last_mouse_y;
};

struct CubeCommandState : CommandState {
    CubeCommandState(Cube* cube);
    virtual ~CubeCommandState();
    void handle(const sf::Event& event, float delta_time);

    Cube* m_cube;

};

struct LightCommandState: CommandState {
    LightCommandState(Light* light);
    virtual ~LightCommandState();
    void handle(const sf::Event& event, float delta_time);

    Light* m_light;

};


#endif

