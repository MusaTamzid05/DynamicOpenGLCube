#include "command_state.h"
#include "camera.h"
#include "cube.h"


CameraCommandState::CameraCommandState():
    first_mouse_move(true),
    last_mouse_x(-1),
    last_mouse_y(-1) {
}

CameraCommandState::~CameraCommandState() {

}



void CameraCommandState::handle(const sf::Event& event, float delta_time) {
    if(event.type == sf::Event::KeyPressed) {

        if(event.key.code == sf::Keyboard::W) 
            Camera::get_instance()->handle_keyboard(Camera::Direction::Forward, delta_time);

        if(event.key.code == sf::Keyboard::S) 
            Camera::get_instance()->handle_keyboard(Camera::Direction::Backward, delta_time);

        if(event.key.code == sf::Keyboard::A) 
            Camera::get_instance()->handle_keyboard(Camera::Direction::Left, delta_time);

        if(event.key.code == sf::Keyboard::D) 
            Camera::get_instance()->handle_keyboard(Camera::Direction::Right, delta_time);

        if(event.key.code == sf::Keyboard::Up) 
            Camera::get_instance()->handle_keyboard(Camera::Direction::Up, delta_time);

        if(event.key.code == sf::Keyboard::Down) 
            Camera::get_instance()->handle_keyboard(Camera::Direction::Down, delta_time);


    }

    if(event.type == sf::Event::MouseMoved) {
        sf::Vector2i mouse_position =  sf::Mouse::getPosition();
        float mouse_pos_x = (float)mouse_position.x;
        float mouse_pos_y = (float)mouse_position.y;

        if(first_mouse_move) {
            last_mouse_x = mouse_pos_x;
            last_mouse_y = mouse_pos_y;
            first_mouse_move = false;
        }

        float x_offset = mouse_pos_x - last_mouse_x;
        float y_offset = last_mouse_y - mouse_pos_y;

        last_mouse_x = mouse_pos_x;
        last_mouse_y = mouse_pos_y;

        Camera::get_instance()->handle_mouse_movement(x_offset, y_offset);

    }

    if(event.type == sf::Event::MouseLeft)
        first_mouse_move = true;

}

CubeState::CubeState(Cube* cube):m_cube(cube) {

}

CubeState::~CubeState() {

}




void CubeState::handle(const sf::Event& event, float delta_time) {
    if(event.type != sf::Event::KeyPressed)
        return;


    if(event.key.code == sf::Keyboard::W) 
        m_cube->increase_triangle();

    if(event.key.code == sf::Keyboard::S) 
        m_cube->decrease_triangle();

}














