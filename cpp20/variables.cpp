#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char**argv) {

    int unitializedInt;
    int initializedInt { 7 };

    cout << "uninitialized int: " << unitializedInt << endl;
    cout << "initialized int: " << initializedInt << endl;

    float f { 1.01f};
    double d { 1/3 };
    long double ld {1.01L };
    cout << "float: " << f << endl;
    cout << "double: " << d << endl;
    cout << "long double: " << ld << endl;

    /*
    std::byte b {72};
    std::string s = std::format("byte: {}", b);
    cout << s;
    */




    return 0;
}
