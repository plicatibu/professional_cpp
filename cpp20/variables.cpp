#include <iostream>
#include <cstddef> // to_integer
#include <format>
#include <limits>

using std::cout;
using std::endl;
int main(int argc, char **argv) {

    int unitializedInt;
    int initializedInt{7};

    cout << "uninitialized int: " << unitializedInt << endl;
    cout << "initialized int: " << initializedInt << endl;

    float f{1.01f};
    double d{1.0 / 3};
    long double ld{1.01L};
    cout << "float: " << f << endl;
    cout << "double: " << d << endl;
    cout << "long double: " << ld << endl;

    std::byte b {72};
    cout << "using just cout -> std::byte b{72} = " << std::to_integer<unsigned int>(b) << "\n"; 
    //cout << std::format("using std::format -> std::byte b{72} = {}", std::to_integer<unsigned int>(b)) << '\n';
    cout << std::format("using std::format -> std::byte b {{72}} = {}", std::to_integer<unsigned int>(b)) << '\n';

    // page 65
    cout << "Limits" << endl;
    cout << "int:" << endl;
    cout << std::format("Min int value: {}\n", std::numeric_limits<int>::min());
    cout << std::format("Max int value: {}\n", std::numeric_limits<int>::max());
    cout << std::format("Lowest int value: {}\n", std::numeric_limits<int>::lowest());

    cout << "double:" << endl;
    cout << std::format("Min double value: {}\n", std::numeric_limits<double>::min());
    cout << std::format("Max double value: {}\n", std::numeric_limits<double>::max());
    cout << std::format("Lowest double value: {}\n", std::numeric_limits<double>::lowest());

    cout << "long double:" << endl;
    cout << std::format("Min long double value: {}\n", std::numeric_limits<long double>::min());
    cout << std::format("Max long double value: {}\n", std::numeric_limits<long double>::max());
    cout << std::format("Lowest long double value: {}\n", std::numeric_limits<long double>::lowest());
    cout << std::format("long double precison (digits10): {}\n", std::numeric_limits<long double>::digits10);


    // casting page 65
    float f2 { 2.87 };
    int i1 = (int) f2; // method 1 - from C - NOT recommended
    int i2 = int (f2); // method 2 - rarely used - NOT recommended
    int i3 = static_cast<int>(f2); // method 3 - RECOMMENDED
    int i4 = f2; // implicit casting
    float large_float = 2200000000.9;
    int i5 = large_float;  // implicit casting with a larger value than int can store.
    cout << std::format("int i1 = (int) {} = {}\n", f2, i1);
    cout << std::format("int i2 = int {} = {}\n", f2, i2);
    cout << std::format("int i3 = static_cast<int>({}) = {}\n", f2, i3);
    cout << std::format("int i4 = {} = {}\n", f2, i4);
    cout << "large_float: " << large_float << endl;
    cout << std::format("int i5 = {} = {}\n", large_float, i5);









    return 0;
}
