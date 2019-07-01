#include "c-echo.h"

int main(int argv, char** argc) {
    std::string ret = "";
    std::cout << echo(argv, argc);
    ret += "\n";
    //return ret;
}
