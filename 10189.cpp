#include <cstdio>

int main(int argc, char* argv[]) {
    int rows, columns, fieldNum = 1;
    char field[100][101];

    while (scanf("%i %i", &rows, &columns) != EOF && rows && columns) {
        
        for (int i = 0; i < rows; ++i){
            scanf("%s", field[i]);
            for (int j = 0; j < columns; ++j)
                if (field[i][j] != '*') field[i][j] = '0';
        }

        for (int i = 0; i < rows; i++) 
            for (int j = 0; j < columns; j++)
                if (field[i][j] == '*')
                    for (int k = i-1; k <= i+1; k++)
                        for (int l = j-1; l <= j+1; l++)
                            if (k >= 0 && k < rows && l >= 0 && l < columns && field[k][l] != '*')
                                field[k][l]++;

        if (fieldNum != 1) printf("\n");

        printf("Field #%i:\n", fieldNum++);

        for (int i = 0; i < rows; ++i)
            printf("%s\n", field[i]);
    }

    return 0;
}
