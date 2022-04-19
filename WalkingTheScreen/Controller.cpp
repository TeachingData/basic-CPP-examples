//
// Created by JGreenwell on 4/18/2022.
//

#include "windows.h"

class Controller {
public:
    Controller() = default;

    /*
    char getDirection() {
        if (GetAsyncKeyState(VK_UP) < 0) {
            return 'u';
        } else if (GetAsyncKeyState(VK_DOWN) < 0) {
            return 'd';
        } else if (GetAsyncKeyState(VK_LEFT) < 0) {
            return 'l';
        } else if (GetAsyncKeyState(VK_RIGHT) < 0) {
            return 'r';
        }
    }*/

    // Let's make the task static: to just call it by itself
    static char getDirection() {
        if (GetKeyState(VK_UP) & 0x8000) {
            return 'u';
        } else if (GetKeyState(VK_DOWN) & 0x8000) {
            return 'd';
        } else if (GetKeyState(VK_LEFT) & 0x8000) {
            return 'l';
        } else if (GetKeyState(VK_RIGHT) & 0x8000) {
            return 'r';
        } else {
            return '\0'; // bad return null
        }
    }

};