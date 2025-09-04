#include <iostream>
#include <cstddef> // to_integer
#include <format>  // include for g++
#include <limits>
#include <cmath>
#include <compare>

using std::cout;
using std::endl;


// function name __func__ page 80
int addNumbers(int number1, int number2) {
    cout << std::format("Entering function {}", __func__) << endl;
    return number1 + number2;
}

[[nodiscard]] int myFunc() {
    return 42;
}

[[nodiscard ("Reason why you should not discard the return value")]] int myFunc2() {
    return 42;
}




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

    // infinty / NaN page 66
    // NOTE: The integer division 0/0 is un undefined behaviour in C++, so std::isnam returns false.
    int i6 = 0/0;
    cout << std::format("i6 = 0/0 is a NaN ? {}\n", std::isnan(i6));

    // NOTE: The float / double 0/0 is a NaN so std::isnan returns NaN.
    float f3 = 0.0/0;
    cout << std::format("f3 = 0/0 is a NaN ? {}\n", std::isnan(f3));

    cout << "float infinity = " << std::numeric_limits<float>::infinity() << endl;
    cout << "double infinity = " << std::numeric_limits<double>::infinity() << endl;
    cout << std::format("float infinity = {}\n", std::numeric_limits<float>::infinity());

    int rem = 10%3;
    cout << "rem = 10 %% 3 = " << rem << endl;
    // NOTE: It makes no sense get remaining of float / double values in a division and it's an error in C++
    //float frem = 10.0f % 3.0f;
    //cout << "rem = 10 % 3.0 " << frem << endl;

    int i7 = 8;
    int i8 {1};
    cout << "i7 = " << i7 << " i8 = " << i8 << endl;
    i7 ^= i8;
    cout << "i7 ^ i8 = " << i7 << endl;

    // enumeration page 69
    enum class PieceType { King, Queen, Rook, Pawn };
    // if PieceType.Queen == 2 // it is an invalid code. You cannot compare enums.
    enum class State { Unknown, Started, Finished };
    enum class Error { None, BadInput, DiskFull, Unknown, };

    //old enum style. It has a problem of names clashing. The example below does not compile.
    //ALWAYS use stronged typed `enum class`.
    /*
     * bool ok { false };
     * enum status { ok, nok }
     * cout << "ok ? " << ok << endl;
     * cout << "status::ok? " << status::ok << endl;
     */

    // switch page 74
    enum class Mode { Default, Custom, Standard };
    Mode mode = Mode::Custom;
    switch (mode) {
        case Mode::Custom:
            cout << "custom...\n";
            [[fallthrough]];
        case Mode::Standard:
            cout << "standard...\n";
            break;
        case Mode::Default:
            cout << "default...\n";
            break;
    };


    switch (mode) {
        using enum Mode;
        case Custom:
            cout << "2 - custom...\n";
            [[fallthrough]];
        case Standard:
            cout << "2 - standard...\n";
            break;
        case Default:
            cout << "2 - default...\n";
            break;
    };

    // three-way comparison page 77
    std::strong_ordering result { 4 <=> 5 };
    if (std::strong_ordering::less == result) {
        cout << "4 is less than 5\n";
    } else if (std::strong_ordering::equal == result) {
        cout << "4 is equal 5\n";
    } else if (std::strong_ordering::greater == result) {
        cout << "4 is greater than 5\n";
    }

    /* We cannot use strong_ordering and parcial_ordering cannot be used on `switch` neither with `using enum`
    switch(result) {
        case std::strong_ordering::less:
            cout << "4 is less than 5\n";
        case std::strong_ordering::equal:
            cout << "4 is equal 5\n";
        case std::strong_ordering::greater:
            cout << "4 is greater than 5\n";
    }
    */

    result = 28 <=> 7;
    if (std::is_lt(result)) { cout << "28 is greater than 7\n"; }
    if (std::is_eq(result)) { cout << "28 is equal 7\n"; }
    if (std::is_gt(result)) { cout << "28 is greater than 7\n"; }

    // function name __func__ page 80
    // The function below will print "Entering function addNumbers".
    addNumbers(14, 14);

    // the compiler will issue an warning due the [[nodiscard]] attribute added to it.
    myFunc();
    myFunc2();

  // my unindented comment.
  if true { cout << "true\n" ; }











    return 0;
}
