// [[noreturn]] attribue - page 82

#include <iostream>
#include <cstdlib>

/*
 * if [[noreturn]] were not present, we'd get a warning as shown below:
 *  noreturnattrib.cpp|15 col 32| warning: control reaches end of non-void function [-Wreturn-type]
 *  ||    15 |         forceProgramTermination();
 *  ||       |         ~~~~~~~~~~~~~~~~~~~~~~~^~
 */
[[noreturn]] void forceProgramTermination() { std::exit(1); }

bool isDongleAvailable() {
    bool isAvailable{false};
    return isAvailable;
}

bool isFeatureLicensed(int featureId) {
    if (!isDongleAvailable()) {
        forceProgramTermination();
    } else {
        bool isLicensed{featureId == 2};
        return isLicensed;
    }
}

int main() {

    bool isLicensed{isFeatureLicensed(42)};
    std::cout << "is licensed ? " << isLicensed << std::endl;
    return 0;
}
