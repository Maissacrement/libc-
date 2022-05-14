#include <iostream>
#include <libA.h>
#include <libB.h>
#include <libC.h>

int main () {
    std::cout << "hello from main" << std::endl;
    helloA();
    helloB();
    libC::helloC();

    return 0;
}