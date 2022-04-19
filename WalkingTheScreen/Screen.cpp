// Holds our background and its functions
#include <array>
#include <iostream>
#include <fstream>
// #include <filesystem> // to check current_path

class Screen {
private:
    // Our screen
    std::array<std::array<char, 12>, 12> screen;
    std::string background = "\n";

public:
    Screen() {
        // fill each individual array with a space character
        reset_screen();
    }

    void reset_screen() {
        // use a reference to ensure filling our screen (change in memory)
        for (auto &a : screen) {
            // a.fill(' '); // we will use this for the real screen but to make seeing easier
            a.fill('.');
        }
    }

    // add_char just adds a char to existing screen (x&y reversed)
    // add_chars adds 3 characters to a line
    // add_chars with 12 - adds a full line
    void add_char(int y, int x, char pixel) { screen[y][x] = pixel; }

    void add_chars(int y, int x, std::array<char, 3> image) {
        for (int i=0; i<image.size(); i++) {
            screen[y][i+x] = image[i];
        }
    }

    void add_line(int y, std::array<char, 12> image) {
        // cause 12 = line
        for (int i=0; i<image.size(); i++) {
            screen[y][i] = image[i];
        }
    }

    void print_screen() {
        for (auto a : screen) {
            for (auto pixel : a) {
                std::cout << pixel;
            }
            std::cout << "\n";
        }
    }

    // These will load the background and print it
    void load_background(std::string name) {
        // std::cout << std::filesystem::current_path(); // Why cause we in cmake-build-debug
        std::ifstream bg ("../Images/" + name + ".txt");
        std::string line;
        if (bg.is_open()) {
            while (std::getline(bg, line)) {
                background += line + "\n";
            }
            bg.close();
        } else {
            std::cout << "Could not open file " + name + ".txt\n";
        }
    }
    void print_background() { std::cout << background; }

    // cleaning this up and leaving portable
    // Now prints as many newlines as needed based on char array size
    void clear_screen() {
        for (int i=0; i<screen.size()-1; i++) {
            std::cout << "\n";
        }
        std::cout << std::endl; // force flush
    }
};
