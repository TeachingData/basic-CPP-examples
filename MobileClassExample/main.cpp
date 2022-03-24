#include <iostream>
#include "Mobile.cpp"

int main() {
    Mobile m = Mobile(1231516, 1234546);
    std::cout << "the IMEI is " << m.IMEI << "\n";

    m.setstorage(128);
    std::cout << "the storage is " << m.getstorage() << "\n";

    m.setsimtype("ESIM");
    std::cout << "Your sim is a " << m.getsimtype() << "\n";

    m.setdate(24, 2022, "march");
    std::cout << "The date today is " << m.getdate() << "\n";
    return 0;
}
