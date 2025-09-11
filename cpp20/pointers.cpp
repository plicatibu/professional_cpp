// scopes - page 101, 103
#include <format>
#include <iostream>

using namespace std;

class Demo {
public:
    int get() { return 5; }
    int salary { 100'000 };
};

Demo *getDemo() {
    Demo *d = new Demo();
    return d;
}

void mysteryFunction(const std::string* s) {
    //*s = "Hello, MAO"; // This won't compile!
}


int main() {

    Demo* pd { getDemo() };

    cout << format("demo -> get() = {}\n", pd -> get());
    cout << format("(*pd).salary = {}\n", (*pd).salary);
    cout << format("(*pd) -> salary = {}\n", pd -> salary);

    delete pd;
    pd = nullptr;

    int size { 3 };
    int *myarray = { new int[size] };
    myarray[0] = 7;
    myarray[1] = 2;
    myarray[2] = 8;
    //myarray[3] = 4;


    // create a pointer that can point to other regions and whose values of theses regions can be changed
    int *ip {};
    ip = new int[10];
    ip[4] = 7;
    delete[] ip;

    // create a pointer that can point to other regios BUT the content of these regions cannot change
    const int *ip2 {};
    ip2 = new int[10];
    cout << "ip2[0] = " << ip2[0] << endl;
    delete[] ip2;
    // ip2[4] = 4;  // it doesn't compile
    ip2 = myarray;
    cout << "ip2[0] = " << ip2[0] << endl;

    // create a pointer that can point to other regios BUT the content of these regions cannot change
    // now using an alternative declaration
    int const *ip3 {};
    ip3 = new int[2];
    // ip3[0] = 28;  // it doesn't compile
    cout << "ip3[0] = " << ip3[0] << endl;
    delete[] ip3;
    ip3 = myarray;  // it doesn't compile because I'm trying to reassign the pointer ip3 to another region.

    // create a pointer that cannot point to other regions BUT the content of the pointed region can be changed
    int* const ip4 {nullptr};
    //ip4 = new int[4]; // it doesn't compile
    //ip[4] = 5;  // error: dereferrencing a null pointer

    // for pointers that cannot be reassinged, they must be initialized on declaration
    int* const ip5 = new int[] {0, 1, 2, 3};
    ip5[0] = 71;
    cout << "ip5[0] = " << ip5[0] << endl;
    delete[] ip5;

    delete[] myarray;

    return 0;
}
