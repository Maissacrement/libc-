#include <iostream>
#include "includes/main.h"

EXPORT void libC::helloC ()
{
    std::cout << "Using libC" << std::endl;
}

int main () {
    libC::helloC();

    return 0;
}