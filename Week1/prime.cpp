#include <iostream>
#include <cmath>

void isPrime(int);

int main() {
    int number;

    do {
        std::cout << "Input a number to check if it is prime (we include negatives): (CTRL-C to quit)" << std::endl;
        std::cin >> number;
        isPrime(number);
    } while (true); // Uh-oh

    return(0);
}

void isPrime(int number) {
    int num = std::abs(number);

    int sqrtNum = std::sqrt(num);

    for (int modulusNum = 2; modulusNum <= sqrtNum; modulusNum++) {
        if ((num % modulusNum) == 0) {
            std::cout << "Number " << num << " is NOT a prime" << std::endl;
            return;
        }
    }

    std::cout << "Number " << number << " is a prime" << std::endl;
}