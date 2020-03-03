/*--------------------------------
    Hunt J. Sparra, 2020
    Practical C++, Exercise 13.2

    A program that takes a list
    of numbers and outputs the
    total, using a check
    class.
----------------------------------*/

#include <iostream>

class check {
    private:
        int running_total;

    public:
        void add_item(int amount) {
            running_total += amount;
        }
        
        int total() {
            return running_total;
        }

        check() {
            running_total = 0;
        }
};

int main() {
    check checkbook;

    for (int i=0; i<100; i++) {
        checkbook.add_item(i);
        std::cout << "Balance after adding " << i << ": " << checkbook.total() << std::endl;
    }

    return 0;
}