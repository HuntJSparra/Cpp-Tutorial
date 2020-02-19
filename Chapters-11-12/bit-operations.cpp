#include <iostream>
#include <cassert>

const int INT_SIZE = 8;

const int X_SIZE = 8;
const int Y_SIZE = 8;

char graphics[X_SIZE / INT_SIZE][Y_SIZE];

inline void set_bit(const int, const int);
inline void clear_bit(const int, const int);
inline void test_bit(const int, const int);

void print_graphics();

int main() {
    int loc;

    for (loc = 0; loc < X_SIZE; ++loc) {
        set_bit(loc, loc);
        test_bit(loc, loc);
    }

    print_graphics();

    for (loc = 0; loc < X_SIZE; ++loc) {
        clear_bit(loc, loc);
        test_bit(loc, loc);
    }

    print_graphics();

    return(0);
}

inline void set_bit(const int x, const int y) {
    assert((x >= 0) && (x < X_SIZE));
    assert((y >= 0) && (y < Y_SIZE));

    graphics[x / INT_SIZE][y] |= static_cast<char>(0x80 >> (x%INT_SIZE));
}

inline void clear_bit(const int x, const int y) {
    assert((x >= 0) && (x < X_SIZE));
    assert((y >= 0) && (y < Y_SIZE));

    graphics[x / INT_SIZE][y] &= static_cast<char>(~(0x80 >> (x%INT_SIZE)));
}

inline void test_bit(const int x, const int y) {
    assert((x >= 0) && (x < X_SIZE));
    assert((y >= 0) && (y < Y_SIZE));

    const int mask = static_cast<char>((0x80 >> (x%INT_SIZE)));

    if ((graphics[x / INT_SIZE][y] & mask) != 0) {
        std::cout << "Bit set" << std::endl;
    } else {
        std::cout << "Bit is not set" << std::endl;
    }
}

void print_graphics() {
    int x, y;
    int bit;

    for (y = 0; y < Y_SIZE; ++y) {
        for (x = 0; x < X_SIZE / INT_SIZE; ++x) {
            for (bit = 0x80; bit > 0; bit = (bit >> 1)) {
                assert((x >= 0) && (x < (X_SIZE/INT_SIZE)));
                assert((y >= 0) && (y < Y_SIZE));

                if ((graphics[x][y] & bit) != 0) {
                    std::cout << 'X';
                } else {
                    std::cout << ". ";
                }
            }
            std::cout << std::endl;
        }
    }
}