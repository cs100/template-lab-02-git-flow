#include "c-echo.h"

int main(int argv, char** argc) {
    std::cout << echo(argv, argc);
    std::cout << "\n";
}
