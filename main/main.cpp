#include <iostream>

#include "Magic.hpp"

int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    Magic magic;
    std::cout << magic.get() << std::endl;

    return EXIT_SUCCESS;
}