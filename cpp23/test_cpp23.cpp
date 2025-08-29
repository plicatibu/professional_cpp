#include <print>
#include <vector>
#include <ranges>
#include <stacktrace>
#include <expected>
#include <flat_map>

struct Example {
    void func(this auto&& self, int x) {
        std::println("Deducing this: x = {}", x);
    }
};

auto divide(int a, int b) -> std::expected<int, std::string> {
    if (b == 0) return std::unexpected("Division by zero");
    return a / b;
}

int main() {
    // std::println
    std::println("Hello, C++23!");

    // Ranges
    auto vec = std::vector{1, 2, 3, 4, 5};
    for (auto x : vec | std::views::filter([](int n) { return n % 2 == 0; })) {
        std::println("Even: {}", x);
    }

    // Deducing this
    Example{}.func(42);
    const Example{}.func(99);

    // Multidimensional subscript
    int arr[2][3] = {{1, 2, 3}, {4, 5, 6}};
    std::println("arr[1,2] = {}", arr[1][2]);

    // std::stacktrace
    auto trace = std::stacktrace::current();
    std::println("Stacktrace size: {}", trace.size());

    // std::expected
    auto result = divide(10, 2);
    if (result) {
        std::println("Division result: {}", *result);
    } else {
        std::println("Error: {}", result.error());
    }

    // std::flat_map
    std::flat_map<int, std::string> fm = {{1, "one"}, {2, "two"}};
    std::println("flat_map[1] = {}", fm[1]);

    return 0;
}
