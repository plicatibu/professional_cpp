// 01_helloworld.cpp
#include <iostream>

int main(void) {
	std::cout << "There are " << 219 << " days I love you "<< std::endl;
    std::cout << std::format("There are {} days I love you", 219) << std::endl;
    std::cout << std::format("There are {} days I love you\n", 219);
}

