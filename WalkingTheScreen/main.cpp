#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "Screen.cpp"
#include "Characters/PlayerCharacter.cpp"
#include "Controller.cpp"


int main() {
    // create instance variables
    Screen screen = Screen();
    PlayerCharacter pc = PlayerCharacter();
    Controller cont = Controller();

    // First print out the background just as an example
    // Really should be in while loop
    screen.load_background("boss");
    screen.print_background();

    // I'm gonna move this to the controller later
    auto scene_periods = std::chrono::seconds(2);
    auto next_period = std::chrono::steady_clock::now() + scene_periods;

    // Draw initial point (start)
    screen.add_chars(pc.x_pos, pc.y_pos, pc.get_model());
    screen.print_screen();

    // Let's move to the bottom (3 - 11)
    for (int i=3; i<12; i++) {
        pc.x_pos += 1; // cause always moving down


        while (std::chrono::steady_clock::now() < next_period) {
            switch(cont.getDirection()) {
                // up = rotate (add later), down = "faster" + 1 to x_pos
                // right/left = right or left
                case 'r':
                    if (pc.y_pos < 11) { pc.y_pos += 1; }
                    break;
                case 'l':
                    if (pc.y_pos > 0) { pc.y_pos -= 1; }
                    break;
                case 'd':
                    if (pc.x_pos > 10) { pc.x_pos += 1; }
                    break;
            }
            std::this_thread::sleep_for (std::chrono::seconds(1));
        }
        // we reached this point + more seconds
        next_period += scene_periods;

        screen.reset_screen();
        screen.clear_screen();
        screen.add_chars(pc.x_pos, pc.y_pos, pc.get_model());
        screen.print_screen();

        // note sure if I need this
        //std::this_thread::sleep_for (std::chrono::seconds(5));
    }

    return 0;
}
