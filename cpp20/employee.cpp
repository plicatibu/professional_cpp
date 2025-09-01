import <iostream>
import <format>
import employee

using namespace std;

int main(int argc, char** argv) {
    Employee anEmployee;
    anEmployee.firstInitial = 'M';
    anEmployee.lastInitial = 'O';
    anEmployee.employeeNumber = 71;
    anEmployee.salary = 100'000;

    cout << format("Employee: {}{}\n", anEmployee.firstInitial, anEmployee.lastInitial);
}
