#include "window.h"
#include <iostream>
#include "headers.h"
#include "consts.h"
#include "cube.h"
#include "camera.h"
#include "command_state.h"



Window::Window(const std::string& title):m_running(false) {

    sf::ContextSettings settings;
    settings.depthBits = 24;
    settings.stencilBits = 8;
    settings.antialiasingLevel = 4;
    settings.majorVersion = 3;
    settings.minorVersion = 0;

    m_window = new sf::RenderWindow(
            sf::VideoMode(WIDTH, HEIGHT),
            title,
            sf::Style::Default,
            settings
            );
    GLenum err = glewInit();

    if(err != GLEW_OK) {
        std::cerr << "Could not init glew\n";
        exit(1);
    }



    glEnable(GL_DEPTH_TEST);
    

    m_cube = new Cube();
    Camera::get_instance()->init(glm::vec3(0.0f, 0.0f, 4.0f));

    m_camera_state_index = 0;
    m_camera_states.push_back(new CameraCommandState());


}

Window::~Window() {
    delete m_window;

}

void Window::run() {
    m_running = true;


    sf::Clock clock;
    sf::Time frame_per_seconds = sf::seconds(1.0f / 60.0f);
    sf::Time time_since_last_frame = sf::Time::Zero;


    while(m_running) {
        sf::Time elased_time = clock.restart();
        time_since_last_frame += elased_time;

        while(time_since_last_frame > frame_per_seconds) {
            handle_event(frame_per_seconds.asSeconds());
            update(frame_per_seconds.asSeconds());
            time_since_last_frame -= frame_per_seconds;

        }

        render();

    }

    m_window->close();

}

void Window::handle_event(float delta_time) {
    sf::Event event;

    while(m_window->pollEvent(event)) {
        if(event.type == sf::Event::Closed)
            m_running = false;

        if(event.type == sf::Event::KeyPressed) {
            if(event.key.code == sf::Keyboard::Escape) {
                m_running = false;
                break;

            }

        }

        m_camera_states[m_camera_state_index]->handle(event, delta_time);


    }

    /*

    if(event.key.code == sf::Keyboard::O) 
        m_cube->increase_triangle();

    if(event.key.code == sf::Keyboard::P) 
        m_cube->decrease_triangle();
        */

}


void Window::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    m_cube->render();
    m_window->display();

}


void Window::update(float delta_time) {
    Camera::get_instance()->update_camera_vectors();
    m_cube->update();
}
