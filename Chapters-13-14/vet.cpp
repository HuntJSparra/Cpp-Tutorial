/*--------------------------------
    Hunt J. Sparra, 2020
    Practical C++, Exercise 14.2

    A program that defines three
    animal related classes and
    returns the total instances of
    all three.
----------------------------------*/

#include <iostream>

class Pig {
    public:
        static int total_pigs;

        Pig() {
            total_pigs++;
        }

        ~Pig() {
            total_pigs--;
        }
};
int Pig::total_pigs = 0;

class Horse {
    public:
        static int total_horses;

        Horse() {
            total_horses++;
        }
};
int Horse::total_horses = 0;

class Dog {
    public:
        static int total_dogs;

        Dog() {
            total_dogs++;
        }
};
int Dog::total_dogs = 0;

int total_animals() {
    return Pig::total_pigs + Horse::total_horses + Dog::total_dogs;
}

int main() {
    Pig p1, p2, p3;
    Horse h1, h2;
    Dog d1, d2, d3, d4, d5;

    std::cout << total_animals() << std::endl;

    return 0;
}