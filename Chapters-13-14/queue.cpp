/*--------------------------------
    Hunt J. Sparra, 2020
    Practical C++, Exercise 13.3

    An implementation of a simple
    FIFO queue.
----------------------------------*/

#include <iostream>
#include <list>

template <typename T>
class queue {
    // A glorified wrapper for list
    private:
        std::list<T> backing;

    public:
        int size() {
            return backing.size;
        }

        void put(T val) {
            backing.push_front(val);
        }

        T get() {
            // Pop, but the exercise specifies that it be called "get"
            // Remove and return the last element from the queue
            T back = backing.back;
            backing.pop_back();
            return back;
        }
};

int main() {
    queue<int> q;
    for (int i=0; i<100; i++) {
        q.put(i);
    }

    for (int i=99; i>=0; i--) {
        std::cout << i << std::endl;
    }

    return 0;
}