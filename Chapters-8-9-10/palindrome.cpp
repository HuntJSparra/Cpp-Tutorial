#include <iostream>
#include <string>

void isPalindrome(std::string);

int main() {
    std::string word;

    std::cout << "This program checks if a word is a palindrome (CASE-SENSITIVE)" << std::endl << std::endl;

    do {
        std::cout << "Input word(s) to check (q to quit): " << std::endl;
        std::cin >> word;
        isPalindrome(word);
    } while (word.compare("q") != 0 && !std::cin.eof());

    return(0);
}

void isPalindrome(std::string word) {
    int head = 0;
    int tail = word.size()-1;

    if (word.compare("q") == 0) {
        return;
    }

    while (head < tail) {
        if (word.at(head) != word.at(tail)) {
            std::cout << "The word \"" << word << "\" is NOT a palindrome" << std::endl;
            return;
        }

        head++; tail--;
    }

    std::cout << "The word \"" << word << "\" is a palindrome" << std::endl;
}