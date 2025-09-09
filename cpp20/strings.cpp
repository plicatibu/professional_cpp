// strings - page 91
#include <format>
#include <iostream>

using namespace std;

int main() {
    std::string s = {"Hello, MAO"};
    cout << format("My text: {}\n", s);
    cout << format("The 7th letter: {}\n", s[7]);
    return 0;
}
