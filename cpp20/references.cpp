// page 109
#include <iostream>

using std::cout;
using std::endl;
using std::string;

string getString() { return "MAO"; }

int main() {
    int x { 3 };
    int y { 7 };
    int &rx { x };


    cout << "x  = " << x << endl;
    cout << "y  = " << y << endl;
    cout << "rx = " << rx << endl;

    x++;
    cout << "\n\n" << endl;
    cout << "x = x + 1 => x = " << x << endl;
    cout << "y  = " << y << endl;
    cout << "rx = " << rx << endl;

    rx = y;
    cout << "\n\n" << endl;
    cout << "Assigning y to rx just copy y value to rx (and x)" << endl;
    cout << "rx = y ==> rx = " << rx << endl;
    cout << "y  = " << y << endl;
    cout << "rx = " << rx << endl;

    y++;
    cout << "\n\n" << endl;
    cout << "y = y + 1 will increment y but neither x nor rx" << endl;
    cout << "x  = " << x << endl;
    cout << "y  = " << y << endl;
    cout << "rx = " << rx << endl;

    int z { 10 };
    const int &rz1 { z };
    int const &rz2 { z };
    cout << "\n\n" << endl;
    cout << "z   = " << z << endl;
    cout << "zr1 = " << rz1 << endl;
    cout << "zr2 = " << rz2 << endl;
    // rz1 = 0;  // this code does not compile
    // rz2 = 3;  // this code does not compile
    cout << "const refs cannnot update the refered variable" << endl;
    cout << "rz1 = 0 does not compile" << endl;
    z = 28;
    cout << "z   = " << z << endl;
    cout << "zr1 = " << rz1 << endl;
    cout << "zr2 = " << rz2 << endl;

    cout << "\n\n" << endl;
    cout << "you cannot create a reference to an unamed value such an int" << endl;
    cout << "int &unnamedRef { 5 };" << endl;
    cout << "you can create a reference to a const unnamed value" << endl;
    cout << "const int &unamedRef { 5 };" << endl;
    // int &unnamedRef { 5 }; // this code doesn't compile
    int const &unnamedRef { 5 };


    cout << "\n\n" << endl;
    cout << "You cannot have a reference for a non-const object" << endl;
    cout << "string &str { getString() }; won't compile" << endl;
    // string &str = { getString() };  // won't compile
    cout << "But you can have a reference for a const object" << endl;
    cout << "string const &str { getString() };" << endl;
    string const &str = { getString() };
    cout << str << endl;




 
    return 0;
}
