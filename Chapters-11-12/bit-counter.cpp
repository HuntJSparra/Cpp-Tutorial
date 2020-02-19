#include <iostream>
#include <limits>

int count_bits(int);

int main() {
    int intput; // It's a pun

    do {
        std::cin >> intput;

        std::cout << count_bits(intput) << std::endl;
    } while (!std::cin.eof());
}

int count_bits(int number) {
    int numBitsSet = 0;

    // Handling negative numbers
    if (number < 0) {
        numBitsSet++;
        number ^= ~(std::numeric_limits<int>::max());
    }

    while (number > 0) {
        if ((number & 1) > 0) {
            numBitsSet++;
        }

        number >>= 1;
    }

    return(numBitsSet);
}