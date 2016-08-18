#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    std::vector<std::vector<int>> blocks = {{-1}};
    std::string action, specifier;
    int numBlocks, a, b;

    while (std::cin >> numBlocks) {
        std::cin.ignore();
        for (int i = 0; i < numBlocks; ++i)
            blocks[i][0] = i;
        while (std::cin >> action >> a >> specifier >> b) {
            std::cin.ignore();
            if (action == "quit") break;
            if (a == b /*or a no stack de b*/) continue;
            if (action == "move" and specifier == "onto") {
                // limpa tudo em cima de a
                // limpa tudo em cima de b
            }
            if (action == "move" and specifier == "over") {
                // limpa tudo em cima de a
                // coloca tudo em cima dos amigos de b
            }
            if (action == "pile" and specifier == "onto") {
                // move a e seus amigos para b
                // limpa tudo em cima de b
            }
            if (action == "pile" and specifier == "over") {
                // move a e seus amigos para b
                // coloca tudo em cima dos amigos de b
            }
        }
        
        for (int i = 0; i < numBlocks; ++i) {
            std::cout << i << ":";
            for (int j = 0; blocks[i][j] > 0; ++j)
                std::cout << " " << blocks[i][j];
            std::cout << "\n";
        }
    }



    return 0;
}
