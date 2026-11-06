#include "ssrb.h"
#include <iostream>

int main()
{
    ssrb::Index index(1000000000ULL, 1000);

    bool inserted = index.insert(1000000001ULL);

    bool found = index.contains(1000000001ULL);

    std::cout << "SSRB Public API Test\n";
    std::cout << "Inserted: " << inserted << "\n";
    std::cout << "Found: " << found << "\n";
    std::cout << "Size: " << index.size() << "\n";

    return 0;
}