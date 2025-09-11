// constexpr vs consteval page 107

#include <format>
#include <iostream>


constexpr double intToMm(double inch) { return inch * 2.54; }

consteval double intToMm2( double inch ) { return inch * 2.54; }

int main() {
    constexpr double const_inch { 6.0 };
    constexpr double mm1 { intToMm( const_inch ) };  // at compile time

    double dynamic_inch { 8.0 };
    double mm2 { intToMm( dynamic_inch ) };  // at run time

    constexpr double dynamic_inch2 { 8.0 };
    double mm3 { intToMm2( dynamic_inch2 ) };
    double mm4 { intToMm2( dynamic_inch2 ) };

    double dynamic_inch3 { 8.0 };
    //double mm4 { intToMm2( dynamic_inch3 ) };  // It's not possible to call consteval function with a not constexpr variable.

    //consteval double dynamic_inch2 { 8.0 }; // NOTE: Variables CANNOT be declared as consteval

    std::cout << mm1 << std::endl;
    std::cout << mm2 << std::endl;    
    std::cout << mm3 << std::endl;
    std::cout << mm4 << std::endl;

    return 0;
}
