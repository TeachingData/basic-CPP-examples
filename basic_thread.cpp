/* Simple program to ensure threads working
 * Will add file handling and other techniques in later versions
 * Make sure to compile with one of the following: 
 *      g++ -pthread -o thread_practice.exe thread_practice.cpp
 *      g++ -lpthread -o thread_practice.exe thread_practice.cpp
 * You need to specify which thread (system) library should be linked in Linux (l = std link, p=only libpthread.a linux)
 */

#include <iostream>
#include <thread>

// dummy function (we'll count over sleeping)
void sleep_function(int n) {
        std::cout << "Thread (called using function pointer) started\n";

        for (int i=0; i<n; i++) {
                std::cout << "Thread at " << i << "\n";
        }

        std::cout << "Thread complete\n";
}

// A callable object for using our thread (same as above just using object)
class thread_obj {
public:
        void operator()(int x) {
                std::cout << "Thread (called using a callable object's function started\n";

                for (int i=0; i<x; i++) {
                        std::cout << "Thread at " << i << "\n";
                }

                std::cout << "Thread complete\n";
        }
};

int main() {
        std::cout << "Threads 1, 2, and 3 will operate independently\n";

        // Thread 1 launching using pointer
        std::thread th1(sleep_function, 3);

        // Thread 2 launching using a callable
        std::thread th2(thread_obj(), 3);

        // Thread 3 using a lambda Expression as an anonymous callable function
        auto af = [](int x) {
                std::cout << "Threads can use anonymous functions as callables\n";
                for (int i=0; i<x; i++) {
                        std::cout << "Thread at " << i << "\n";
                }
                std::cout << "Thread complete\n";
        };

        std::thread th3(af, 3);

        // now we just wait for each to finish
        th1.join();
        th2.join();
        th3.join();

        return 0;
}
