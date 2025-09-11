// NULL and nullptr page 103
#include <format>
#include <iostream>

using namespace std;

void func(int i) { cout << "func(int) = " << i << "\n"; }

int main() {

    func(NULL);
    //func(nullptr);  // It doesn't allow the function func be called
    return 0;
}
