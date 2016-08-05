#include <iostream>
#include <string>
#include <cctype>

bool equalsInvalidChar(const char &a) {
    if (a == ' ' or a == '.' or a == ',' or a == '!' or a == '?') {
        std::cout << a << " a shit\n";
        return true;
    }
    return false;
}

int main(int argc, char* argv[]) {

    std::string line;
    bool isPalindrome;

    while (getline(std::cin, line) and line != "DONE") {
        isPalindrome = true;
        for (int i = 0, j = line.size()-1; i <= j and isPalindrome; ++i, j--) {
            while (equalsInvalidChar(line[i])) {
                i++;
                std::cout << "skipped i\n";
            }
            while (equalsInvalidChar(line[j])) {
                j++;
                std::cout << "skipped j\n";
            }

            if (line[i] != line[j]){
                isPalindrome = false;
                std::cout << "failed at "<< i << " and " << j << "\n";
            }
        }

        if (isPalindrome)
            std::cout << "You won't be eaten!\n";
        else
            std::cout << "Uh oh..\n";
    }


    return 0;
}
