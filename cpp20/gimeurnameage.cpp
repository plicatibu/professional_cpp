// 01_helloworld.cpp
#include <iostream>
#include <string>
#include <format>

namespace maocode {
    void mao(std::string name, int age) {
        std::string result = std::format("Inside mao function: {} is {} years old\n", name, age);
        std::cout << result;
    }
}

int main(int argc, char** argv) {
    std::string name;
    std::cout << std::format("What's your name?\n");
    std::cin >> name;

    std::cout << std::format("How old are you?\n");
    int age;
    std::cin >> age;

    std::string result = std::format("Hi, {}. You're {} years old\n", name, age);
    std::cout << result;
    //std::cout << std::format("There are {} days I love you\n", 219);

    maocode::mao(name, age);
}

