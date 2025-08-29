#include <iostream>

namespace mao::cumpliments::utils {
    void test(void) {
        std::cout << "from mao::cumpliments::utils\n" ; 
    }   
}

namespace mao {
    namespace tools {
        namespace utils {
            void test(void) {
                std::cout << "from mao::tools::utils\n";
            }
        }   
    }
}

namespace mytools = mao::tools::utils;

int main(void) {
    mao::cumpliments::utils::test();
    mao::tools::utils::test();
    mytools::test();

    std::cout << "hexadecimal float point 0x3.FFp0: " << 0x3.FFp0 << std::endl;
    std::cout << "hexadecimal float point 0xF.1p1: " << 0xF.1p-1 << std::endl;
    std::cout << "hexadecimal float point 0xF.1p0: " << 0xF.1p0 << std::endl;
    std::cout << "hexadecimal float point 0xF.1p1: " << 0xF.1p1 << std::endl;
    std::cout << "hexadecimal float point 0xF.1p2: " << 0xF.1p2 << std::endl;

    std::cout << "digits separator 28'071'971: " << 28'071'971 << std::endl;

    return 0;
}
