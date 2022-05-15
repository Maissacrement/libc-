#include <iostream>
#include "includes/curlpattern.h"

// Driver Code
int main()
{
    int apple_count {0};
    std::cout << "This program returns the integer value "
              << apple_count
              << "\n";
    fetch("https://dummyjson.com/products");

    return 0;
}