#include <iostream>

void add(float&);
void subtract(float&);
void multiply(float&);
void divide(float&);
void modulus(float&);
void power(float&);

int main() {
    char symbol;

    float total = 0;

    do {
        std::cout << "Input a symbol (+, -, *, /, ^) and number" << std::endl;

        std::cin >> symbol;
        switch (symbol) {
            case '+':
                add(total);
                break;
            case '-':
                subtract(total);
                break;
            case '*':
                multiply(total);
                break;
            case '/':
                divide(total);
                break;
            case '^':
                power(total);
                break;
            default:
                std::cout << "Final total is: " << total << std::endl;
                return(0);
        }
        std::cout << "Current total: " << total << std::endl;
    } while (!std::cin.eof()); // uh-oh

    return 0;
}

void add(float& total) {
    float amount;
    std::cin >> amount;

    total += amount;
}

void subtract(float& total) {
    float amount;
    std::cin >> amount;

    total -= amount;
}

void multiply(float& total) {
    float amount;
    std::cin >> amount;

    total *= amount;
}

void divide(float& total) {
    float amount;
    std::cin >> amount;

    total /= total;
}

void power(float& total) {
    float amount;
    std::cin >> amount;

    if (amount == 0) {
        total = 1;
    } else {
        float original = total;
        for (; amount>0; amount--) {
            total *= original;
        }
    }
}
