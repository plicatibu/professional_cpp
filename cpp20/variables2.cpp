#include <array>
#include <format>
#include <iostream>
#include <optional>
#include <vector>

using std::cout;
using std::endl;

void func(const int arr[], const int len) {
    cout << "size of arr: " << len << endl;
    for (int i = 0; i < len; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    } // for
}

template <size_t N> void func2(const std::array<int, N> arr) {
    int len = arr.size();
    cout << "size of arr: " << len << endl;
    for (int i = 0; i < len; i++) {
        cout << "arr[" << i << "] = " << arr[i] << endl;
    } // for
}
std::optional<int> getData(bool giveIt) {
    if (giveIt) {
        return 71;
    }
    return std::nullopt; // or simply `return {};`
};

int main() {
    const int size = 3;
    int array1[size] = {0};
    int array2[size] = {};
    int array3[size]{};
    char array4[size]{};
    int array5[] = {7, 8, 9};

    for (int i = 0; i < size; i++) {
        cout << "array1[" << i << "] = " << array1[i] << endl;
        cout << "array2[" << i << "] = " << array2[i] << endl;
        cout << "array3[" << i << "] = " << array3[i] << endl;
        cout << "array4[" << i << "] = -->" << array4[i] << "<--" << endl;
        cout << "array5[" << i << "] = " << array5[i] << endl;
    }

    cout << "size of array3: " << std::size(array3) << endl;
    cout << "size of array4: " << std::size(array4) << endl;
    cout << "size of array5: " << std::size(array5) << endl;

    func(array3, 3);

    std::array<int, 3> arr{9, 8, 7};
    cout << "array size: " << arr.size() << endl;
    cout << "second element: " << arr[1] << endl;

    std::array arr2 = {1, 2, 3};
    cout << "array size: " << arr2.size() << endl;
    cout << "second element: " << arr2[1] << endl;

    func2(arr);

    std::vector<int> myVector{11, 22};
    myVector.push_back(33);
    cout << "first element of myVector: " << myVector[0] << endl;
    cout << "last element of myVector: " << myVector[myVector.size() - 1]
         << endl;

    std::pair<double, int> myPair{28.07, 1971};
    cout << std::format("Pair elements: {}, {}\n", myPair.first, myPair.second);

    std::optional<int> data1{getData(true)};
    std::optional<int> data2{getData(false)};
    cout << "data1.has_value? " << data1.has_value() << endl;
    if (data1) {
        cout << "data1 value: " << *data1 << endl;
    }
    if (data2) {
        cout << "data2 has valued." << endl;
    } else {
        cout << "data2 has NO value" << endl;
    }

    return 0;
}
