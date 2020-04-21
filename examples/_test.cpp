// Used for testing, do not use it as an example
#include <iostream>

#include "qpp.h"
#include "experimental/experimental.h"

int main() {
    /////////// testing ///////////
    using namespace qpp;

    double p = 0.8;
    std::map<bool, int> hist;
    for (idx i = 0; i < 10000; ++i)
        ++hist[bernoulli(p)];

    std::cout << hist[true] << ' ' << hist[false] << '\n';
}
