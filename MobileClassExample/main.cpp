#include <iostream>
#include "Mobile.cpp"

int main() {
  // Just used to show the basic object creation and calls to the class
    Mobile m = Mobile();
    std::cout << "the IMEI is " << m.IMEI << "\n";

    m.setstorage(128);
    std::cout << "the storage is " << m.getstorage() << "\n";

    m.setsimtype("ESIM");
    std::cout << "Your sim is a " << m.getsimtype() << "\n";
    m.send_text("Yeah! Text!");
    return 0;
}
