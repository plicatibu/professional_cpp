#include <iostream>

using namespace std;

double divideNumbers(double numerator, double denominator) {
    if (denominator == 0) {
        throw invalid_argument { "Denominators cannot be 0"};
    }
    return numerator / denominator;
}

int main() {
    try {
        cout << divideNumbers(2.3, 0) << endl;
    } catch (const invalid_argument &exception) {
        cout << format("Exception caught: {}", exception.what()) << endl;
    }
    return 0;
}
