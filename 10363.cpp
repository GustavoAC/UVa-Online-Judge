#include <cstdio>
#include <cstring>

int main(int argc, char* argv[]) {
    int numGames, numX, numO, winX, winO;
    char matriz[3][4];

    while (scanf("%i\n", &numGames) != EOF) {
        for (int i = 0; i < numGames; ++i) {
            numX = 0, winX = 0;
            numO = 0, winO = 0;

            for (int j = 0; j < 3; ++j)
                scanf("%s\n", matriz[j]);

            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    if (matriz[j][k] == 'X')
                        numX++;
                    else if (matriz[j][k] == 'O')
                        numO++;

            // Horizontal
            for (int j = 0; j < 3; ++j){
                if (!strcmp("XXX", matriz[j])) winX++;
                else if (!strcmp("OOO", matriz[j])) winO++;
            }

            // Vertical
            for (int j = 0; j < 3; j++) {
                if (matriz[0][j] == 'X' && matriz[1][j] == 'X' && matriz[2][j] == 'X') winX++;
                else if (matriz[0][j] == 'O' && matriz[1][j] == 'O' && matriz[2][j] == 'O') winO++;
            }

            // Diagonal
            if (matriz[0][0] == 'X' && matriz[1][1] == 'X' && matriz[2][2] == 'X') winX++;
            else if (matriz[0][0] == 'O' && matriz[1][1] == 'O' && matriz[2][2] == 'O') winO++;
            if (matriz[0][2] == 'X' && matriz[1][1] == 'X' && matriz[2][0] == 'X') winX++;
            else if (matriz[0][2] == 'O' && matriz[1][1] == 'O' && matriz[2][0] == 'O') winO++;

            if ((numX == numO or numX -1 == numO) and (!winX or !winO) and
                ((!winX and !winO) or (winO and numX == numO) or (winX and numX -1 == numO))) {
                printf("yes\n");
            } else {
                printf("no\n");
            }
        }
    }


    return 0;
}
