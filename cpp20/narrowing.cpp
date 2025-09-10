#include <format>
#include <iostream>

using namespace std;


void func(int x) {
    cout << format("func: x = {}\n", x);
}

int main() {
    int y = 3.14; // implicity conversion to int
    // int y {1.14}; // it will generate and error because it doesn't allow implicity convertion.

    cout << format("main: y = {}\n", y);
    func(3.14);
    // func( { 3.14 }); // it will generate an error because it doens't allow implicity conversion.
    return 0;
}
