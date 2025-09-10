// scopes - page 101
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
    myarray[3] = 4;
    return 0;
}
