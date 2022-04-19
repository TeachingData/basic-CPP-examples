// Base class to hold all animations for "person"

#include "People.h"

class Mob : public People {
public:
    // constructor sets up the character class (yep overriden)
    Mob() {
        base_model[0] = '1';
        base_model[1] = '-';
        base_model[2] = '1';
    }

    // set and get models
    void set_model(std::array<char, 3> image) override { this->base_model = image; }
    void set_model(std::string image) override {
        // sent a string so just set first 3 chars (index 0-2)
        for (int i=0; i<3; i++) {
            this->base_model[i] = image[i];
        }
    }
    // actually the getter is already made


};
