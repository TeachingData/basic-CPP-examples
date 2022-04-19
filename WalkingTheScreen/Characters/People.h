//
// This is the template for all our player, npcs, bosses, enemies, etc...
// Used as a base for all other "people"
// As this is/will be a template = we have code in the header
//

#ifndef WALKINGTHESCREEN_PEOPLE_H
#define WALKINGTHESCREEN_PEOPLE_H

#include <array>
#include <string>
#include <vector>

class People {
protected:
    // so let's move to a full pixel: so its easy to set individual pixels
    // Here model has a horizontal point(index), a vertical point, and a character
    struct pixel {
        int h_idx = 0; // first index (horizontal)
        int v_idx = 0; // second index (vertical)
        char image = '\0';
    };
    // Now a vector of our models which we can then write to screen
    std::array<char, 3> base_model{};

    struct stats {
        int hp = 100;
        int mp = 10;
        int strength = 3;
        int mind = 3;
        int dexterity = 3;
        int vitilaty = 3;
        std::string job = "wealking";
        std::string race = "human";
    };

public:
    // positions of base model
    int x_pos = 0;
    int y_pos = 0;

    // set default deconstructor - indicate it is virtual
    People() = default;

    // set and get models
    virtual void set_model(std::array<char, 3>) = 0;
    virtual void set_model(std::string) = 0;
    virtual std::array<char, 3> get_model() { return base_model; };

    // Could add virtual method and others here
};

#endif //WALKINGTHESCREEN_PEOPLE_H
