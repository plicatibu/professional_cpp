// scopes - page 96
#include <format>
#include <iostream>

using namespace std;

class Demo {
public:
    int get() { return 5; }
};

// global scope
int get() { return 10; }

namespace NS {
    int get() { return 20; }
}

// if used it will cause an error an error due ambiguity.
//using namespace NS;


int main() {
    Demo d;
    cout << d.get() << endl;  // d scope
    cout << NS::get() << endl; // NS scope
    cout << ::get() << endl; // global scope
    cout << get() << endl; // global scope
    return 0;
}
