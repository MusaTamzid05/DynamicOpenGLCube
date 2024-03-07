#ifndef WINDOW_H
#define WINDOW_H


namespace sf {
    class Window;
    class Event;
};

#include <string>
#include <vector>

struct Cube;
struct CommandState;
struct Light;

struct Command {
    Command();

    std::vector<CommandState*> command_states;
    int m_command_state_index;

    void handle(const sf::Event& event, float delta_time);
    void change_state();
};

struct Window {
    Window(const std::string& title="Window");
    virtual ~Window();

    void run();

    void handle_event(float delta_time);
    void render();
    void update(float delta_time);


    sf::Window* m_window;
    Cube* m_cube;
    Light* m_light;
    bool m_running;

    Command command;





};

#endif
