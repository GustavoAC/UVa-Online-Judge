#include <iostream>
#include <string>
#include <cctype>

bool equalsInvalidChar(const char &a) {
    if (a == ' ' or a == '.' or a == ',' or a == '!' or a == '?')
        return true;
    return false;
}

int main(int argc, char* argv[]) {
    std::string line;
    bool isPalindrome;

    while (getline(std::cin, line) and line != "DONE") {
        isPalindrome = true;
        for (int i = 0, j = line.size()-1; i <= j and isPalindrome; ++i, j--) {
            while (equalsInvalidChar(line[i])) i++;
            while (equalsInvalidChar(line[j])) j--;

            if (tolower(line[i]) != tolower(line[j])) isPalindrome = false;
        }

        if (isPalindrome)
            std::cout << "You won't be eaten!\n";
        else
            std::cout << "Uh oh..\n";
    }


    return 0;
}
