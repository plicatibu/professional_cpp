// initializer_list page 90
#include <iostream>
#include <initializer_list>
#include <format>

using namespace std;

auto makeSum(initializer_list<int> values) {
    int total {0};
    for (int value: values) {
        total += value;
    }
    return total;
}

int main() {
    int a { makeSum({1, 2, 3}) };
    int b { makeSum({10, 20, 30, 40, 50, 60})};
    cout << format("a = {}\n", a);
    cout << format("b = {}\n", b);
    return 0;
}
