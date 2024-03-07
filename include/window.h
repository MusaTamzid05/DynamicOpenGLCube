#ifndef WINDOW_H
#define WINDOW_H


namespace sf {
    class Window;
};

#include <string>
#include <vector>

struct Cube;
struct CameraCommandState;

struct Window {
    Window(const std::string& title="Window");
    virtual ~Window();

    void run();

    void handle_event(float delta_time);
    void render();
    void update(float delta_time);


    sf::Window* m_window;
    Cube* m_cube;
    bool m_running;


    std::vector<CameraCommandState*> m_camera_states;
    int m_camera_state_index;



};

#endif
