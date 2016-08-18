#include <iostream>
#include <algorithm>
#include <vector>

int findPos(const std::vector<int> &stack, const int &value) {
    return std::find(stack.begin(), stack.end(), value) - stack.begin();
}

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> blocks(25, std::vector<int>(25, -1));
    std::vector<int> currentStackOf(25);
    std::string action, specifier;
    int numBlocks, a, b;
    int posA, posB;
    while (std::cin >> numBlocks) {
        std::cin.ignore();
        for (int i = 0; i < numBlocks; ++i) {
            blocks[i][0] = i;
            currentStackOf[i] = i;
        }
        while (std::cin >> action >> a >> specifier >> b) {
            std::cin.ignore();
            if (action == "quit") break;
            if (a == b or currentStackOf[a] == currentStackOf[b]) continue;

            posA = findPos(blocks[currentStackOf[a]], a);
            posB = findPos(blocks[currentStackOf[b]], b);
            if (action == "move" and specifier == "onto") {
                // Return those from above a
                for (int i = posA+1; blocks[currentStackOf[a]][i] >= 0; ++i) {
                    int &currentValue = blocks[currentStackOf[a]][i];

                    blocks[currentValue][0] = currentValue;
                    currentStackOf[currentValue] = currentValue;
                    currentValue = -1;
                }

                // Return those from above b
                for (int i = posB+1; blocks[currentStackOf[b]][i] >= 0; ++i) {
                    int &currentValue = blocks[currentStackOf[b]][i];

                    blocks[currentValue][0] = currentValue;
                    currentStackOf[currentValue] = currentValue;
                    currentValue = -1;
                }

                // Puts a over b
                blocks[currentStackOf[a]][posA] = -1;
                blocks[currentStackOf[b]][posB+1] = a;
                currentStackOf[a] = currentStackOf[b];
            } else if (action == "move" and specifier == "over") {
                // Return those from above a
                for (int i = posA+1; blocks[currentStackOf[a]][i] >= 0; ++i) {
                    int &currentValue = blocks[currentStackOf[a]][i];

                    blocks[currentValue][0] = currentValue;
                    currentStackOf[currentValue] = currentValue;
                    currentValue = -1;
                }

                // Finds b's top
                int bTop;
                for (bTop = posB+1; blocks[currentStackOf[b]][bTop] >= 0; bTop++);

                // Puts a over b's friends
                blocks[currentStackOf[a]][posA] = -1;
                blocks[currentStackOf[b]][bTop] = a;
                currentStackOf[a] = currentStackOf[b];
            } else if (action == "pile" and specifier == "onto") {
                // Return those from above b
                for (int i = posB+1; blocks[currentStackOf[b]][i] >= 0; ++i) {
                    int &currentValue = blocks[currentStackOf[b]][i];

                    blocks[currentValue][0] = currentValue;
                    currentStackOf[currentValue] = currentValue;
                    currentValue = -1;
                }

                // Finds a's top
                int aTop;
                for (aTop = posA+1; blocks[currentStackOf[a]][aTop] >= 0; aTop++);

                // Puts a and its friends over b
                for (int i = aTop-1-posA; 0 <= i; i--) {
                    int &currentValue = blocks[currentStackOf[a]][posA+i];

                    blocks[currentStackOf[b]][posB+1+i] = currentValue;
                    currentStackOf[currentValue] = currentStackOf[b];
                    currentValue = -1;
                }
            } else if (action == "pile" and specifier == "over") {
                // Finds a's top
                int aTop;
                for (aTop = posA+1; blocks[currentStackOf[a]][aTop] >= 0; aTop++);

                // Finds b's top
                int bTop;
                for (bTop = posB+1; blocks[currentStackOf[b]][bTop] >= 0; bTop++);

                // Puts a and its friends over b's top
                for (int i = aTop-1-posA; 0 <= i; i--) {
                    int &currentValue = blocks[currentStackOf[a]][posA+i];

                    blocks[currentStackOf[b]][bTop+i] = currentValue;
                    currentStackOf[currentValue] = currentStackOf[b];
                    currentValue = -1;
                }
            }
        }

        for (int i = 0; i < numBlocks; ++i) {
            std::cout << i << ":";
            for (int j = 0; blocks[i][j] >= 0; ++j)
                std::cout << " " << blocks[i][j];
            std::cout << "\n";
        }
    }

    return 0;
}
